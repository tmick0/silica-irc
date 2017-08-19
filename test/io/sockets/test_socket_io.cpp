#include <gtest/gtest.h>

#include <fstream>

#include "io/sockets/io_socket.h"

using namespace silica;
using namespace silica::io::sockets;

TEST(test_io_socket, can_construct) {
    io_socket *s;
    ASSERT_NO_THROW(s = new io_socket());
    ASSERT_NO_THROW(delete s);
}
