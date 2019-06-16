#include <gtest/gtest.h>

#include <fstream>

#include "protocol/commands.h"
#include "protocol/deserialize.h"
#include "protocol/numeric.h"

using namespace silica::protocol;

TEST(test_protocol, can_construct) {
    ASSERT_NO_THROW(std::make_shared<command_mode>(std::list<std::string>{"#test", "+o", "test"}));
}

TEST(test_protocol, can_serialize) {
    command_mode c(std::list<std::string>{"#test", "+o", "test"});
    const std::string expected = "MODE #test +o test\n";
    const std::string result = c.serialize();
    ASSERT_EQ(expected, result);
}

TEST(test_protocol, stream_operator) {
    {
        command_mode c(std::list<std::string>{"#test", "+o", "test"});
        std::stringstream ss;
        ss << c;
        ASSERT_EQ(c.serialize(), ss.str());
    }

    {
        rpl_motdstart c(std::list<std::string>{"nick", "irc-server.example.com message of the day"});
        std::stringstream ss;
        ss << c;
        ASSERT_EQ(c.serialize(), ss.str());
    }
}

TEST(test_protocol, can_serialize_varlen) {
    command_topic c(std::list<std::string>{"#test", "foo bar baz"});
    const std::string expected = "TOPIC #test :foo bar baz\n";
    const std::string result = c.serialize();
    ASSERT_EQ(expected, result);
}

TEST(test_protocol, can_deserialize) {
    const command_mode expected(std::list<std::string>{"#test", "+o", "test"});
    const std::string input = ":irc-server.example.com MODE #test +o test";
    auto result = deserialize(input)->command();
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(expected, *result);
}

TEST(test_protocol, can_deserialize_varlen) {
    command_topic expected(std::list<std::string>{"#test", "foo bar baz"});
    const std::string input = ":irc-server.example.com TOPIC #test :foo bar baz";
    auto result = deserialize(input)->command();
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(expected, *result) << *result;
}

TEST(test_protocol, can_deserialize_numeric) {
    rpl_motdstart motdstart(std::list<std::string>{"nick", "irc-server.example.com message of the day"});
    const std::string input = ":irc-server.example.com 375 nick :irc-server.example.com message of the day";
    auto result = deserialize(input)->numeric();
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(motdstart, *result) << *result;
}
