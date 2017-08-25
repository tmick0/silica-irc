add_executable(
    silica_io_sockets_test
    test_socket_io.cpp
    test_io_thread.cpp
)

target_link_libraries(
    silica_io_sockets_test
    silica_io_sockets
    gtest_main
)

add_test(
    silica_io_sockets_tests
    ${EXECUTABLE_OUTPUT_PATH}/silica_io_sockets_test
)
