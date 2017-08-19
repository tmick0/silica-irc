add_executable(
    silica_io_test
    test_io_file.cpp
    test_io_manager.cpp
)

target_link_libraries(
    silica_io_test
    silica_io
    gtest_main
)

add_test(
    silica_io
    ${EXECUTABLE_OUTPUT_PATH}/silica_io_test
)

add_subdirectory("sockets")
