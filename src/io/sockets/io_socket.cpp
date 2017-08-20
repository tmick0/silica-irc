#include "io_socket.h"

#include <sys/ioctl.h>

namespace silica {
namespace io {
namespace sockets {

io_socket::io_socket()
: m_connected(false)
{
    if((m_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        make_error("socket()");
    }
}

io_socket::~io_socket()
{
    if(m_connected && shutdown(m_fd, SHUT_RDWR) == -1) {
        make_error("shutdown()");
    }
}

bool io_socket::valid() {
    return m_connected;
}

size_t io_socket::avail() const {
    size_t avail;
    if(ioctl(m_fd, FIONREAD, &avail) == -1){
        make_error("ioctl(): errno = " << errno);
    }
    return avail;
}


}
}
}
