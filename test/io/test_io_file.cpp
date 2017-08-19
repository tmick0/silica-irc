#include <gtest/gtest.h>

#include <fstream>

#include "io/io_file.h"

using namespace silica::io;

TEST(test_io_file, can_construct) {
    io_file *s;
    ASSERT_NO_THROW(s = new io_file("/dev/null"));
    ASSERT_NO_THROW(delete s);
}

TEST(test_io_file, can_read) {
    std::ifstream s;
    s.open("/proc/uptime");

    std::string expected;
    s >> expected;

    io_file f("/proc/uptime");
    std::vector<uint8_t> result = f.read(expected.size());
    std::string result_str ((char *) result.data(), result.size());

    ASSERT_EQ(result_str, expected);
}
