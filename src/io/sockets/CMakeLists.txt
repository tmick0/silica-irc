set(lib_name "${lib_name}_sockets")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES io_socket.cpp io_socket_impl.cpp io_socket_detail_tcp4.cpp io_socket_detail_tcp6.cpp io_socket_types.cpp
    HEADERS io_socket.h   io_socket_impl.h   io_socket_detail_tcp4.h   io_socket_detail_tcp6.h   io_socket_types.h
    LIBRARIES silica_common silica_io
    DESTINATION "silica/io/sockets/"
)
