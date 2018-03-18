#include "io_thread.h"

#include "common/error.h"

namespace silica {
namespace io {

io_thread::io_thread(io_manager& manager, std::function<void(io_result const&)> callback, int timeout)
: m_manager(manager)
, m_callback(callback)
, m_timeout(duration_to_timeval(std::chrono::milliseconds(timeout)))
{
}

void io_thread::write(io_base const& io, std::string const& data) {
    std::vector<uint8_t> v (data.begin(), data.end());
    return write(io, v);
}

void io_thread::write(io_base const& io, std::vector<uint8_t> const& data) {
    std::unique_lock<std::mutex> lock (m_writes_lock);

    std::map<io_ref const, std::list<io_result>>::iterator it;
    std::tie(it, std::ignore) = m_pending_writes.emplace(std::make_pair(io_ref{io}, std::list<io_result>{}));

    it->second.emplace_back(io, data, io_result_type::RESULT_WRITE);
    m_write_cond.notify_one();
}

void io_thread::start() {
    if(m_io_thread == nullptr && m_cb_thread == nullptr) {
        m_running = true;
        m_io_thread = std::make_shared<std::thread>(&io_thread::io_loop, this);
        m_cb_thread = std::make_shared<std::thread>(&io_thread::cb_loop, this);
    }
    else {
        make_error("io_thread is already running");
    }
}

void io_thread::stop() {
    m_running = false;
    m_write_cond.notify_one();
    m_io_thread->join();
    m_cb_thread->join();
    m_io_thread = nullptr;
    m_cb_thread = nullptr;
}

void io_thread::cb_loop() {
    while(m_running) {
        std::list<io_result> res = m_manager.read(m_timeout);
        for(io_result const& r : res) {
            m_callback(r);
        }
    }
}

void io_thread::io_loop() {
    while(m_running) {
        std::unique_lock<std::mutex> lock (m_writes_lock);

        // getting past this cv/conditional means either (a) we got a message to write, or (b) it is time to exit
        if(m_running && m_pending_writes.empty()){
            m_write_cond.wait(lock);
        }

        // if we have pending writes, query for writeable sockets
        if(m_running && !m_pending_writes.empty()) {
            for(io_event const& ev : m_manager.get_writeable(m_timeout)) {

                // check each writeable socket for pending writes
                std::map<io_ref const, std::list<io_result>>::iterator it = m_pending_writes.find(io_ref{ev.io});
                if(it != m_pending_writes.end()){
                    // write and consume the first pending message for each socket
                    ev.io.write(it->second.front().result);
                    it->second.pop_front();

                    // if the list is empty, remove it from the map
                    if(it->second.empty()){
                        m_pending_writes.erase(it);
                    }
                }

            }
        }
    }
}



}
}
