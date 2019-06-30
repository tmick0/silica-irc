#include <silica/client/server_context.h>
#include <silica/protocol/commands.h>
#include <silica/protocol/numeric.h>
#include <silica/protocol/prototype.h>

#include <silica/client/client.h>
#include <silica/client/hooks.h>
#include <chrono>

using namespace silica::protocol;

namespace silica {
namespace client {

server_context::server_context(std::shared_ptr<irc_client> client, const std::string& name,
                               std::shared_ptr<io::io_base> io)
    : m_client(client), m_name(name), m_io(std::move(io)), m_state(context_state::INITIALIZED) {}

std::shared_ptr<protobase> server_context::connect(const std::string& password, const std::string& nick,
                                                   const std::string& user, const std::string& host,
                                                   const std::string& server, const std::string& realname) {
    const command_pass cmd_pass(std::list<std::string>{password});
    m_io->write(cmd_pass.serialize());
    return connect(nick, user, host, server, realname);
}

void server_context::handle_msg(std::shared_ptr<protobase> msg) {
    std::unique_lock<std::mutex> l(m_hooks_mutex);
    for (auto& h : m_hooks) {
        if (h.first == msg->getPrototype()) {
            h.second(msg);
        }
    }
}

server_context::hook_iterator_t server_context::add_hook(prototype t, hook_fn_t fn) {
    std::unique_lock<std::mutex> l(m_hooks_mutex);
    return m_hooks.insert(m_hooks.end(), std::make_pair(t, fn));
}

void server_context::remove_hook(hook_iterator_t h) {
    std::unique_lock<std::mutex> l(m_hooks_mutex);
    m_hooks.erase(h);
}

std::shared_ptr<protobase> server_context::wait_for(std::list<prototype> reply_types, std::chrono::seconds timeout) {
    message_hook h(shared_from_this(), reply_types);
    return h.consume(timeout);
}

void server_context::pong(std::shared_ptr<protobase> m) {
    m_client->schedule([this, m]() {
        const command_pong pong(m->command()->getArgs());
        m_io->write(pong.serialize());
    });
}

std::shared_ptr<protobase> server_context::connect(const std::string& nick, const std::string& user,
                                                   const std::string& host, const std::string& server,
                                                   const std::string& realname) {
    const command_nick cmd_nick(std::list<std::string>{nick});
    const command_user cmd_user(std::list<std::string>{user, host, server, realname});

    m_state = context_state::CONNECTING;
    m_io->write(cmd_nick.serialize());
    m_io->write(cmd_user.serialize());

    auto res =
        wait_for({err_nonicknamegiven::Prototype(), err_erroneusnickname::Prototype(), err_nicknameinuse::Prototype(),
                  err_nickcollision::Prototype(), err_needmoreparams::Prototype(), err_alreadyregistred::Prototype(),
                  rpl_endofmotd::Prototype()},
                 std::chrono::seconds(5));

    if (res->getPrototype() != rpl_endofmotd::Prototype()) {
        make_error(res);
    }

    m_state = context_state::CONNECTED;
    add_hook({command_ping::Prototype()}, [this](std::shared_ptr<protobase> m) { pong(m); });

    return res;
}
}  // namespace client
}  // namespace silica