set(lib_name "${lib_name}_protocol")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES prototype.cpp protobase.cpp commands.cpp numeric.cpp deserialize.cpp
    HEADERS prototype.h   protobase.h   commands.h   numeric.h   deserialize.h
    LIBRARIES silica_common
    DESTINATION "silica/protocol/"
)
