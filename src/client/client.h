#ifndef client_h_
#define client_h_

#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <future>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

#include "io/io_manager.h"
#include "io/io_thread.h"
#include "protocol/protobase.h"
#include "server_context.h"

namespace silica {
namespace client {

class irc_client : public std::enable_shared_from_this<irc_client> {
public:
    irc_client(const std::string& nick, const std::string& user, const std::string& realname);

    std::shared_ptr<server_context> add_server(const std::string& hostname, const std::string& port = "6667");

    void run();
    std::shared_future<void> schedule(std::function<void()>);

protected:
    void io_callback(io::io_result const& res);
    void handle_msg(std::shared_ptr<server_context> context, std::shared_ptr<protocol::protobase>);

private:
    std::string m_nick;
    std::string m_user;
    std::string m_realname;
    io::io_manager m_mgr;
    io::io_thread m_thread;

    std::map<std::string, std::shared_ptr<server_context>> m_servers;
    std::map<const io::io_base*, std::shared_ptr<server_context>> m_servers_io;

    std::condition_variable m_pending_cv;
    std::mutex m_pending_mutex;
    std::list<std::shared_future<void>> m_pending;
};
}  // namespace client
}  // namespace silica

#endif
