set(lib_name "${lib_name}_io")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES io_base.cpp io_events.cpp io_file.cpp io_manager.cpp io_results.cpp io_thread.cpp 
    HEADERS io_base.h   io_events.h   io_file.h   io_manager.h   io_results.h   io_thread.h   io_ref.h
    LIBRARIES silica_common
    DESTINATION "silica/io/"
)

add_subdirectory("sockets")
