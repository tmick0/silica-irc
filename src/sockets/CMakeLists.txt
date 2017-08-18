set(lib_name "${lib_name}_sockets")

add_library(
    ${lib_name}
    SHARED
    socket_wrapper.cpp socket_thread.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
)

add_dependencies(
    ${lib_name}
    silica_common
)
