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
    io_file f("/dev/zero");
    std::vector<uint8_t> result = f.read(10);

    ASSERT_EQ(result.size(), 10u);
    bool all_elements_zero = true;
    for(uint8_t const& b : result){
        all_elements_zero &= (b == 0);
    }
    ASSERT_TRUE(all_elements_zero);
}
