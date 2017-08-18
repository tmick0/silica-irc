set(lib_name "silica")

add_library(
    ${lib_name}
    SHARED
    silica.cpp
)

target_link_libraries(
    ${lib_name}
    silica_sockets
)

install(
    TARGETS silica
    DESTINATION lib
)

install(
    FILES silica.h
    DESTINATION include
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("sockets")
add_subdirectory("common")
