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

/* server queries and commands */

constexpr char CMD_VERSION[] = "VERSION";
constexpr char CMD_STATS[]   = "STATS";
constexpr char CMD_LINKS[]   = "LINKS";
constexpr char CMD_TIME[]    = "TIME";
constexpr char CMD_CONNECT[] = "CONNECT";
constexpr char CMD_TRACE[]   = "TRACE";
constexpr char CMD_ADMIN[]   = "ADMIN";
constexpr char CMD_INFO[]    = "INFO";

typedef command_impl<CMD_VERSION, 0, 1, false> command_version;
typedef command_impl<CMD_STATS,   0, 2, false> command_stats;
typedef command_impl<CMD_LINKS,   0, 2, false> command_links;
typedef command_impl<CMD_TIME,    0, 1, false> command_time;
typedef command_impl<CMD_CONNECT, 1, 2, false> command_connect;
typedef command_impl<CMD_TRACE,   0, 1, false> command_trace;
typedef command_impl<CMD_ADMIN,   0, 1, false> command_admin;
typedef command_impl<CMD_INFO,    0, 1, false> command_info;

/* messages */

constexpr char CMD_PRIVMSG[] = "PRIVMSG";
constexpr char CMD_NOTICE[]  = "NOTICE";

typedef command_impl<CMD_PRIVMSG, 2, 0, true> command_privmsg;
typedef command_impl<CMD_NOTICE,  2, 0, true> command_notice;

/* user queries */

constexpr char CMD_WHO[]    = "WHO";
constexpr char CMD_WHOIS[]  = "WHOIS";
constexpr char CMD_WHOWAS[] = "WHOWAS";

typedef command_impl<CMD_WHO,    0, 2, false> command_who;
typedef command_impl<CMD_WHOIS,  1, 1, false> command_whois;
typedef command_impl<CMD_WHOWAS, 1, 2, false> command_whowas;

/* misc messages */

constexpr char CMD_KILL[]     = "KILL";
constexpr char CMD_PING[]     = "PING";
constexpr char CMD_PONG[]     = "PONG";
constexpr char CMD_ERROR[]    = "ERROR";
constexpr char CMD_AWAY[]     = "AWAY";
constexpr char CMD_REHASH[]   = "REHASH";
constexpr char CMD_RESTART[]  = "RESTART";
constexpr char CMD_SUMMON[]   = "SUMMON";
constexpr char CMD_USERS[]    = "USERS";
constexpr char CMD_WALLOPS[]  = "WALLOPS";
constexpr char CMD_USERHOST[] = "USERHOST";
constexpr char CMD_ISON[]     = "ISON";

typedef command_impl<CMD_KILL,     2, 0, true>  command_kill;
typedef command_impl<CMD_PING,     1, 1, false> command_ping;
typedef command_impl<CMD_PONG,     1, 1, false> command_pong;
typedef command_impl<CMD_ERROR,    1, 0, true>  command_error;
typedef command_impl<CMD_AWAY,     0, 1, true>  command_away;
typedef command_impl<CMD_REHASH,   0, 0, false> command_rehash;
typedef command_impl<CMD_RESTART,  0, 0, false> command_restart;
typedef command_impl<CMD_SUMMON,   1, 1, false> command_summon;
typedef command_impl<CMD_USERS,    0, 1, false> command_users;
typedef command_impl<CMD_WALLOPS,  1, 0, true>  command_wallops;
typedef command_impl<CMD_USERHOST, 1, 0, true>  command_userhost;
typedef command_impl<CMD_ISON,     1, 0, true>  command_ison;

}
}

#endif
