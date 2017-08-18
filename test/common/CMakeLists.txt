add_executable(
    silica_common_test
    test_error.cpp
)

target_link_libraries(
    silica_common_test
    silica_common
    gtest_main
)

add_test(
    silica_common_tests
    ${EXECUTABLE_OUTPUT_PATH}/silica_common_test
)
