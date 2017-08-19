#include <gtest/gtest.h>

#include "io/io_manager.h"
#include "io/io_file.h"

using namespace silica;
using namespace silica::io;

TEST(test_io_manager, add_io) {
    io_manager mgr;
    io_file devnull ("/dev/null");
    mgr.add_io(devnull);
}

TEST(test_io_manager, read) {
    io_manager mgr;
    io_file devnull ("/dev/null");
    mgr.add_io(devnull);
    std::list<io_event> events = mgr.read(1000);
    ASSERT_EQ(events.size(), 1u);
}
