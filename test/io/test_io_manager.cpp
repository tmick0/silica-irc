#include <gtest/gtest.h>

#include <cstdlib>
#include <cstdio>

#include "io/io_manager.h"
#include "io/io_file.h"

using namespace silica;
using namespace silica::io;

TEST(test_io_manager, add_io) {
    io_manager mgr;
    io_file devnull ("/dev/null");
    mgr.add_io(devnull);
}

TEST(test_io_manager, read_zero) {
    io_manager mgr;
    io_file devnull ("/dev/null");
    mgr.add_io(devnull);
    std::list<io_result> events = mgr.read(1000);
    ASSERT_EQ(events.size(), 1u);
    ASSERT_EQ(events.front().result.size(), 0u);
}

TEST(test_io_manager, read_nonzero) {
    std::string test_str ("hello world");

    FILE *tmp = std::tmpfile();
    std::fputs(test_str.c_str(), tmp);
    std::rewind(tmp);

    std::string tmppath ("/proc/self/fd/");
    tmppath += std::to_string(fileno(tmp));

    io_manager mgr;
    io_file f (tmppath);
    mgr.add_io(f);

    std::list<io_result> events = mgr.read(1000);
    ASSERT_EQ(events.size(), 1u);
    ASSERT_EQ(events.front().result.size(), test_str.size());
    for(size_t i = 0; i < test_str.size(); i++) {
        ASSERT_EQ(events.front().result[i], test_str[i]);
    }

    std::fclose(tmp);
}
