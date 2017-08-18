#include <gtest/gtest.h>

#include "sockets/socket_wrapper.h"

using namespace silica;
using namespace silica::sockets;

TEST(test_socket_wrapper, can_construct) {
    socket_wrapper *s;
    ASSERT_NO_THROW(s = new socket_wrapper("localhost", 80));
    ASSERT_NO_THROW(delete s);
}
