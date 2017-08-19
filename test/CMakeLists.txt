
add_library(
    gtest_main
    gtest_main.cpp
)

target_link_libraries(
    gtest_main
    libgtest
)

add_subdirectory("io")
add_subdirectory("common")
