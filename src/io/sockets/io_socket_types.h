#ifndef io_socket_types_h_
#define io_socket_types_h_

#include <silica/io/sockets/io_socket_detail_tcp4.h>
#include <silica/io/sockets/io_socket_detail_tcp6.h>
#include <silica/io/sockets/io_socket_impl.h>

namespace silica {
namespace io {
namespace sockets {

typedef io_socket_impl<detail::io_socket_detail_tcp4> io_socket_tcp4;
typedef io_socket_impl<detail::io_socket_detail_tcp6> io_socket_tcp6;
}
}
}

#endif
