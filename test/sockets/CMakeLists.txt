add_executable(
    silica_sockets_test
    test_socket_wrapper.cpp
)

target_link_libraries(
    silica_sockets_test
    silica_sockets
    gtest_main
)

add_test(
    silica_sockets_tests
    ${EXECUTABLE_OUTPUT_PATH}/silica_sockets_test
)
