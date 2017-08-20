add_definitions(-D__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")

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
