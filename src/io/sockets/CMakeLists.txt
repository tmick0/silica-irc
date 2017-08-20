set(lib_name "${lib_name}_sockets")

add_library(
    ${lib_name}
    SHARED
    io_socket.cpp
    io_socket_impl.cpp
    io_socket_detail_tcp4.cpp
    io_socket_detail_tcp6.cpp
    io_socket_types.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
    silica_io
)

add_dependencies(
    ${lib_name}
    silica_common
    silica_io
)
