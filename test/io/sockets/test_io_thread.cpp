#include <gtest/gtest.h>

#include <fstream>

#include <silica/io/io_thread.h>
#include <silica/io/sockets/io_socket_types.h>

using namespace silica::io;
using namespace silica::io::sockets;

TEST(test_io_thread, lifetime) {
    io_manager manager;

    std::string res_str;

    io_socket_tcp4 s;
    s.connect("google.com", "80");

    manager.add_io(s);

    io_thread thread(manager,
                     [&res_str](io_result const& res) {
                         res_str += std::string{res.result.begin(), res.result.end()};
                     },
                     500);

    thread.start();

    s.write("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    thread.stop();

    ASSERT_EQ(res_str.find("HTTP/1.1"), 0u);
}
