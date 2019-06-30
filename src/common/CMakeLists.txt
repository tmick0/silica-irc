set(lib_name "${lib_name}_common")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES error.cpp time.cpp
    HEADERS error.h   time.h
    DESTINATION "silica/common/"
)
