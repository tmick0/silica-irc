#include <gtest/gtest.h>

#include "common/error.h"

using namespace silica;

TEST(test_error, make_error_throws) {
    ASSERT_THROW(make_error("hello world"), error);
}

TEST(test_error, make_error_what) {
    try {
        make_error("hello" << " world " << 1234 << "!");
    }
    catch(error const& err) {
        EXPECT_NE(strstr(err.what(), "hello world 1234!"), nullptr);
    }
}
