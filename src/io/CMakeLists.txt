set(lib_name "${lib_name}_io")

add_library(
    ${lib_name}
    SHARED
    io_base.cpp io_events.cpp io_file.cpp io_manager.cpp io_results.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
)

add_dependencies(
    ${lib_name}
    silica_common
)

add_subdirectory("sockets")
