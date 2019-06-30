#ifndef io_socket_detail_tcp6_h_
#define io_socket_detail_tcp6_h_

#include <sys/socket.h>

namespace silica {
namespace io {
namespace sockets {
namespace detail {

struct io_socket_detail_tcp6 {
    static constexpr int domain = AF_INET6;
    static constexpr int type = SOCK_STREAM;
};
}  // namespace detail
}  // namespace sockets
}  // namespace io
}  // namespace silica

#endif
