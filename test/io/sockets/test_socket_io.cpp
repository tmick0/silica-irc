#include <gtest/gtest.h>

#include <fstream>

#include "io/io_manager.h"
#include "io/sockets/io_socket.h"
#include "io/sockets/io_socket_types.h"

using namespace silica;
using namespace silica::io;
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

TEST(test_io_socket, can_do_io) {
    io_socket_tcp4 s;
    const std::string request ("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n");
    s.connect("google.com", "80");
    s.write(request);

    io_manager mgr;
    mgr.add_io(s);

    std::list<io_result> res = mgr.read(1000);
    ASSERT_NE(res.size(), 0u);

    std::string res_str (res.front().result.begin(), res.front().result.end());
    ASSERT_EQ(res_str.find("HTTP/1.1"), 0u);
}
