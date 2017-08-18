#ifndef socket_thread_h_
#define socket_thread_h_

#include "sockets/socket_wrapper.h"

namespace silica {
namespace sockets {

class socket_thread {
public:

    socket_thread(std::string const& hostname, uint16_t port)
    : m_socket(hostname, port)
    {

    }

private:
    socket_wrapper m_socket;
};

}
}

#endif
