#ifndef socket_wrapper_h_
#define socket_wrapper_h_

#include <cstdint>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "common/error.h"

namespace silica {
namespace sockets {

class socket_wrapper {
public:
    
    socket_wrapper(std::string const& host, uint16_t port)
    : m_connected(false)
    {
        if((m_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            make_error("socket()");
        }
    }

    ~socket_wrapper()
    {
        if(m_connected && shutdown(m_fd, SHUT_RDWR) == -1) {
            make_error("shutdown()");
        }
        if(close(m_fd) == -1) {
            make_error("close()");
        }
    }

private:

    bool m_connected;
    int m_fd;

};

}
}

#endif
