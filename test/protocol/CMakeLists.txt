add_executable(
    silica_protocol_test
    test_protocol_commands.cpp
)

target_link_libraries(
    silica_protocol_test
    silica_protocol
    gtest_main
)

add_test(
    silica_protocol_test
    ${EXECUTABLE_OUTPUT_PATH}/silica_protocol_test
)
