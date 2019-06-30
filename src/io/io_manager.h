#ifndef io_manager_h_
#define io_manager_h_

#include <silica/common/time.h>
#include <silica/io/io_base.h>
#include <silica/io/io_events.h>
#include <silica/io/io_results.h>

#include <chrono>
#include <functional>
#include <list>
#include <unordered_map>

#include <sys/select.h>

namespace silica {
namespace io {

class io_thread;

class io_manager {
public:
    io_manager() = default;
    void add_io(io_base const& io);

    template <typename R, typename P>
    std::list<io_result> read(std::chrono::duration<R, P> const& timeout) {
        return read(duration_to_timeval(timeout));
    }

    std::list<io_result> read(int timeout = 0);
    std::list<io_result> read(timeval const& timeout);

private:
    int make_fdset(fd_set& fdset) const;
    std::list<io_event> get_readable(timeval const& timeout);
    std::list<io_event> get_writeable(timeval const& timeout);

    std::list<std::reference_wrapper<const io_base>> m_ios;

    friend class io_thread;
};
}
}

#endif
