#include <silica/client/client.h>
#include <silica/client/hooks.h>

#include <silica/io/sockets/io_socket_types.h>
#include <silica/protocol/commands.h>
#include <silica/protocol/deserialize.h>
#include <silica/protocol/numeric.h>

#include <csignal>

namespace silica {
namespace client {

irc_client::irc_client(const std::string& nick, const std::string& user, const std::string& realname)
    : m_nick(nick),
      m_user(user),
      m_realname(realname),
      m_thread(m_mgr, [this](io::io_result const& res) { return io_callback(res); }, 500) {}

std::shared_ptr<server_context> irc_client::add_server(const std::string& hostname, const std::string& port) {
    auto sock = std::make_shared<io::sockets::io_socket_tcp4>();
    m_mgr.add_io(*sock);
    sock->connect(hostname, port);

    auto ctx = std::make_shared<server_context>(shared_from_this(), hostname, sock);
    m_servers.emplace(hostname, ctx);
    m_servers_io.emplace(sock.get(), ctx);

    schedule([this, hostname, ctx]() { ctx->connect(m_nick, m_user, m_user, hostname, m_realname); });

    return ctx;
}

void irc_client::io_callback(io::io_result const& res) {
    if (res.type == io::io_result_type::RESULT_READ) {
        std::string s(res.result.begin(), res.result.end());
        size_t i = 0;
        while (i < s.length()) {
            const size_t j = s.find('\n', i);
            const std::string sub = s.substr(i, j - i);
            try {
                auto msg = protocol::deserialize(sub);
                std::shared_ptr<server_context> server;
                server = m_servers_io.at(&res.io);
                server->handle_msg(msg);

            } catch (const std::exception& e) {
                // TODO: trigger an event on errors here
                std::cerr << "failed to deserialize: " << sub << std::endl;
            }
            if (j == std::string::npos || j == s.length()) {
                break;
            }
            i = j + 1;
        }
    }
}

std::shared_future<void> irc_client::schedule(std::function<void()> fn) {
    auto future = std::async(std::launch::deferred, fn).share();
    std::unique_lock<std::mutex> l(m_pending_mutex);
    m_pending.emplace_back(future);
    m_pending_cv.notify_one();
    return future;
}

void irc_client::run() {
    m_thread.start();

    bool terminate = false;

    while (!terminate) {
        std::shared_future<void> fn;
        {
            std::unique_lock<std::mutex> l(m_pending_mutex);
            m_pending_cv.wait(l, [this]() { return m_pending.size() > 0; });
            fn = m_pending.front();
            m_pending.pop_front();
        }
        fn.get();
    }

    m_thread.stop();
}
}  // namespace client
}  // namespace silica
