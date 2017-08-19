#include <gtest/gtest.h>

#include "io/io_manager.h"

using namespace silica;
using namespace silica::io;

class io_null : public io_base {
public:
    io_null() = default;
    virtual bool valid() override {
        return true;
    }
};

TEST(test_io_manager, add_io) {
    io_manager mgr;
    mgr.add_io(io_null{});

}
