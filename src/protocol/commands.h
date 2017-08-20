#ifndef commands_h_
#define commands_h_

#include "common/error.h"
#include <string>
#include <list>

namespace silica {
namespace protocol {

class command_base {
public:

    virtual std::string serialize() = 0;
    virtual ~command_base() {}

protected:

    command_base() = default;

};

template <char const *CommandString, int NumRequired, int NumOptional, bool LastArgVarLen>
class command_impl : public command_base {
public:

    template <typename Container>
    command_impl(Container const& args)
    : m_args (args.begin(), args.end())
    {
        if(m_args.size() < NumRequired || m_args.size() > NumRequired + NumOptional) {
            make_error("command<" << CommandString << ">(): expected between "
                << NumRequired << " and " << NumRequired + NumOptional
                << " arguments but got " << m_args.size()
            );
        }
    }

    virtual std::string serialize() override {
        std::string res (CommandString);
        for(std::list<std::string>::const_iterator it = m_args.begin(); it != m_args.end(); ){
            res += " ";

            const std::string& arg = *it;
            if(++it == m_args.end() && LastArgVarLen){
                res += ":";
            }

            res += arg;
        }
        res += "\n";
        return res;
    };

private:

    const std::list<std::string> m_args;

};

/* connection/registration commands */

constexpr char CMD_NICK[] = "NICK";
constexpr char CMD_USER[] = "USER";
constexpr char CMD_OPER[] = "OPER";
constexpr char CMD_QUIT[] = "QUIT";

typedef command_impl<CMD_NICK, 1, 0, false> command_nick;
typedef command_impl<CMD_USER, 4, 0, true>  command_user;
typedef command_impl<CMD_OPER, 2, 0, false> command_oper;
typedef command_impl<CMD_QUIT, 0, 1, true>  command_quit;

/* channel commands */

constexpr char CMD_JOIN[]   = "JOIN";
constexpr char CMD_PART[]   = "PART";
constexpr char CMD_MODE[]   = "MODE";
constexpr char CMD_TOPIC[]  = "TOPIC";
constexpr char CMD_NAMES[]  = "NAMES";
constexpr char CMD_LIST[]   = "LIST";
constexpr char CMD_INVITE[] = "INVITE";
constexpr char CMD_KICK[]   = "KICK";

typedef command_impl<CMD_JOIN,   1, 1, false> command_join;
typedef command_impl<CMD_PART,   1, 0, false> command_part;
typedef command_impl<CMD_MODE,   2, 3, false> command_mode;
typedef command_impl<CMD_TOPIC,  1, 1, true>  command_topic;
typedef command_impl<CMD_NAMES,  1, 0, false> command_names;
typedef command_impl<CMD_LIST,   0, 1, false> command_list;
typedef command_impl<CMD_INVITE, 2, 0, false> command_invite;
typedef command_impl<CMD_KICK,   2, 1, true>  command_kick;

}
}

#endif
