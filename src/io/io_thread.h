#ifndef io_thread_h_
#define io_thread_h_

#include <condition_variable>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

#include "io_manager.h"
#include "io_ref.h"
#include "io_results.h"

namespace silica {
namespace io {

class io_thread {
public:
    io_thread(io_manager& manager, std::function<void(io_result const&)> callback, int timeout = 1000);

    void write(io_base const& io, std::vector<uint8_t> const& data);
    void write(io_base const& io, std::string const& data);

    void start();
    void stop();

private:
    void io_loop();
    void cb_loop();

    volatile bool m_running;

    io_manager& m_manager;
    std::function<void(io_result const&)> m_callback;

    timeval m_timeout;

    std::map<io_ref const, std::list<io_result>> m_pending_writes;

    std::mutex m_writes_lock;
    std::condition_variable m_write_cond;

    std::shared_ptr<std::thread> m_io_thread;
    std::shared_ptr<std::thread> m_cb_thread;
};
}
}

#endif
