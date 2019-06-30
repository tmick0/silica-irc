#ifndef server_context_h_
#define server_context_h_

#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <string>

#include <silica/client/context_state.h>
#include <silica/io/io_base.h>
#include <silica/protocol/protobase.h>

namespace silica {
namespace client {

// forward decl
class irc_client;

class server_context : public std::enable_shared_from_this<server_context> {
public:
    server_context(std::shared_ptr<irc_client> client, const std::string& name, std::shared_ptr<io::io_base> io);

    std::shared_ptr<protocol::protobase> connect(const std::string& password, const std::string& nick,
                                                 const std::string& user, const std::string& host,
                                                 const std::string& server, const std::string& realname);
    std::shared_ptr<protocol::protobase> connect(const std::string& nick, const std::string& user,
                                                 const std::string& host, const std::string& server,
                                                 const std::string& realname);

    using hook_fn_t = std::function<void(std::shared_ptr<protocol::protobase>)>;
    using hook_t = std::pair<protocol::prototype, hook_fn_t>;
    using hook_iterator_t = std::list<hook_t>::const_iterator;

    hook_iterator_t add_hook(protocol::prototype t, hook_fn_t fn);
    void remove_hook(hook_iterator_t h);
    void handle_msg(std::shared_ptr<protocol::protobase> msg);

protected:
    std::shared_ptr<protocol::protobase> wait_for(std::list<protocol::prototype> reply_types,
                                                  std::chrono::seconds timeout);

    void pong(std::shared_ptr<protocol::protobase> m);

    std::list<hook_t> m_hooks;
    std::mutex m_hooks_mutex;
    std::shared_ptr<irc_client> m_client;
    std::string m_name;
    std::shared_ptr<io::io_base> m_io;
    context_state m_state;
};

}  // namespace client
}  // namespace silica

#endif
