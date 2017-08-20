#include "io_manager.h"

#include "common/error.h"
#include <errno.h>

namespace silica {
namespace io {

void io_manager::add_io(const io_base& io) {
    m_ios.push_back(std::cref(io));
}

std::list<io_result> io_manager::read(int timeout) {
    return read(std::chrono::milliseconds{timeout});
}

std::list<io_result> io_manager::read(timeval const& timeout) {
    std::list<io_result> result;
    std::list<io_event> ready = get_readable(timeout);
    for(io_event const& e : ready) {
        result.emplace_back(e.io, e.io.read());
    }
    return result;
}

std::list<io_event> io_manager::get_readable(timeval const& timeout) {

    // copy timeval because select may mutate it
    timeval tv (timeout);

    // create fdset
    fd_set fdset;
    const int nfds = make_fdset(fdset);

    // create return list
    std::list<io_event> result;

    // call select()
    int count = select(nfds, &fdset, NULL, NULL, &tv);
    if(count > 0) {
        for(io_base const& sock : m_ios) {
            if(FD_ISSET(sock.m_fd, &fdset)) {
                result.emplace_back(sock, EVENT_READABLE);
            }
        }
    }
    else if(count < 0){
        make_error_errno("select(): ", errno);
    }

    return result;

}

int io_manager::make_fdset(fd_set& fdset) const
{
    int max = -1;
    FD_ZERO(&fdset);
    for(io_base const& sock : m_ios) {
        FD_SET(sock.m_fd, &fdset);
        max = std::max(max, sock.m_fd);
    }
    return max + 1;
}


}
}
