#ifndef io_socket_detail_tcp4_h_
#define io_socket_detail_tcp4_h_

#include <sys/socket.h>

namespace silica {
namespace io {
namespace sockets {
namespace detail {

struct io_socket_detail_tcp4 {
    static constexpr int domain = AF_INET;
    static constexpr int type = SOCK_STREAM;
};
}  // namespace detail
}  // namespace sockets
}  // namespace io
}  // namespace silica

#endif
