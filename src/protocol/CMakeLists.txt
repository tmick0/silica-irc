set(lib_name "${lib_name}_protocol")

add_library(
    ${lib_name}
    SHARED
    prototype.cpp protobase.cpp commands.cpp numeric.cpp deserialize.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
)

add_dependencies(
    ${lib_name}
    silica_common
)
