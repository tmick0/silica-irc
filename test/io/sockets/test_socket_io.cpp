#include <gtest/gtest.h>

#include <fstream>

#include "io/sockets/io_socket.h"
#include "io/sockets/io_socket_types.h"

using namespace silica;
using namespace silica::io::sockets;

TEST(test_io_socket, can_construct) {
    io_socket *s;
    ASSERT_NO_THROW(s = new io_socket_tcp4());
    ASSERT_NO_THROW(delete s);
}

TEST(test_io_socket, can_connect) {
    io_socket_tcp4 s;
    ASSERT_NO_THROW(s.connect("google.com", "80"));
}
