set(lib_name "${lib_name}_protocol")

add_library(
    ${lib_name}
    SHARED
    commands.cpp numeric.cpp
)

target_link_libraries(
    ${lib_name}
    silica_common
)

add_dependencies(
    ${lib_name}
    silica_common
)
