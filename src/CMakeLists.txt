add_definitions(-D__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")

set(lib_name "silica")

silica_add_library(
    TARGET ${lib_name}
    SHARED
    SOURCES silica.cpp
    HEADERS silica.h
    LIBRARIES silica_client
    DESTINATION "silica/"
)

add_subdirectory("common")
add_subdirectory("io")
add_subdirectory("protocol")
add_subdirectory("client")

