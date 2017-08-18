
add_library(
    gtest_main
    gtest_main.cpp
)

target_link_libraries(
    gtest_main
    libgtest
)

add_subdirectory("sockets")
add_subdirectory("common")
