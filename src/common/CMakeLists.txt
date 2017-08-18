set(lib_name "${lib_name}_common")

add_library(
    ${lib_name}
    SHARED
    error.cpp
)
