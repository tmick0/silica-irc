set(lib_name "${lib_name}_client")

add_library(
    ${lib_name}
    SHARED
    client.cpp server_context.cpp context_state.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
    silica_io
    silica_io_sockets
    silica_protocol
)

add_dependencies(
    ${lib_name}
    silica_common
    silica_io
    silica_io_sockets
    silica_protocol
)

