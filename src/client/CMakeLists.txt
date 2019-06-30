set(lib_name "${lib_name}_client")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES client.cpp server_context.cpp context_state.cpp
    HEADERS client.h   server_context.h   context_state.h   hooks.h 
    LIBRARIES silica_common silica_io silica_io_sockets silica_protocol
    DESTINATION "silica/client/"
)
