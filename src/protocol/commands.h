#ifndef commands_h_
#define commands_h_

#include <list>
#include <memory>
#include <string>

#include <silica/common/error.h>
#include <silica/protocol/protobase.h>
#include <silica/protocol/prototype.h>

namespace silica {
namespace protocol {

class command_base : public protobase, public std::enable_shared_from_this<command_base> {
public:
    virtual std::string serialize() const override = 0;
    virtual ~command_base() {}
    bool operator==(const command_base& other) const;

    std::shared_ptr<command_base> command() override { return shared_from_this(); };
    bool isNumeric() const override { return false; }

    const std::list<std::string>& getArgs() const { return m_args; }

protected:
    command_base() = default;

    template <typename Container>
    command_base(Container const& args) : m_args(args.begin(), args.end()) {}

    const std::list<std::string> m_args;
};

template <const char* CommandString, int NumRequired, int NumOptional, bool LastArgVarLen>
class command_impl : public command_base {
public:
    template <typename Container>
    command_impl(Container const& args) : command_base(args) {
        if (m_args.size() < NumRequired || m_args.size() > NumRequired + NumOptional) {
            make_error("command<" << CommandString << ">(): expected between " << NumRequired << " and "
                                  << NumRequired + NumOptional << " arguments but got " << m_args.size());
        }
    }

    std::string serialize() const override {
        std::string res(CommandString);
        for (std::list<std::string>::const_iterator it = m_args.begin(); it != m_args.end();) {
            res += " ";

            const std::string& arg = *it;
            if (++it == m_args.end() && LastArgVarLen) {
                res += ":";
            }

            res += arg;
        }
        res += "\n";

        return res;
    };

    prototype getPrototype() const override { return s_prototype; }

    static prototype Prototype() { return s_prototype; }

protected:
    static const prototype s_prototype;
};

template <const char* CommandString, int NumRequired, int NumOptional, bool LastArgVarLen>
const prototype command_impl<CommandString, NumRequired, NumOptional, LastArgVarLen>::s_prototype = {
    CommandString, CommandString, NumRequired, NumOptional, LastArgVarLen};

/* connection/registration commands */

constexpr char CMD_PASS[] = "PASS";
constexpr char CMD_NICK[] = "NICK";
constexpr char CMD_USER[] = "USER";
constexpr char CMD_OPER[] = "OPER";
constexpr char CMD_QUIT[] = "QUIT";

using command_pass = command_impl<CMD_PASS, 1, 0, false>;
using command_nick = command_impl<CMD_NICK, 1, 0, false>;
using command_user = command_impl<CMD_USER, 4, 0, true>;
using command_oper = command_impl<CMD_OPER, 2, 0, false>;
using command_quit = command_impl<CMD_QUIT, 0, 1, true>;

/* channel commands */

constexpr char CMD_JOIN[] = "JOIN";
constexpr char CMD_PART[] = "PART";
constexpr char CMD_MODE[] = "MODE";
constexpr char CMD_TOPIC[] = "TOPIC";
constexpr char CMD_NAMES[] = "NAMES";
constexpr char CMD_LIST[] = "LIST";
constexpr char CMD_INVITE[] = "INVITE";
constexpr char CMD_KICK[] = "KICK";

using command_join = command_impl<CMD_JOIN, 1, 1, false>;
using command_part = command_impl<CMD_PART, 1, 0, false>;
using command_mode = command_impl<CMD_MODE, 2, 3, false>;
using command_topic = command_impl<CMD_TOPIC, 1, 1, true>;
using command_names = command_impl<CMD_NAMES, 1, 0, false>;
using command_list = command_impl<CMD_LIST, 0, 1, false>;
using command_invite = command_impl<CMD_INVITE, 2, 0, false>;
using command_kick = command_impl<CMD_KICK, 2, 1, true>;

/* server queries and commands */

constexpr char CMD_VERSION[] = "VERSION";
constexpr char CMD_STATS[] = "STATS";
constexpr char CMD_LINKS[] = "LINKS";
constexpr char CMD_TIME[] = "TIME";
constexpr char CMD_CONNECT[] = "CONNECT";
constexpr char CMD_TRACE[] = "TRACE";
constexpr char CMD_ADMIN[] = "ADMIN";
constexpr char CMD_INFO[] = "INFO";

using command_version = command_impl<CMD_VERSION, 0, 1, false>;
using command_stats = command_impl<CMD_STATS, 0, 2, false>;
using command_links = command_impl<CMD_LINKS, 0, 2, false>;
using command_time = command_impl<CMD_TIME, 0, 1, false>;
using command_connect = command_impl<CMD_CONNECT, 1, 2, false>;
using command_trace = command_impl<CMD_TRACE, 0, 1, false>;
using command_admin = command_impl<CMD_ADMIN, 0, 1, false>;
using command_info = command_impl<CMD_INFO, 0, 1, false>;

/* messages */

constexpr char CMD_PRIVMSG[] = "PRIVMSG";
constexpr char CMD_NOTICE[] = "NOTICE";

using command_privmsg = command_impl<CMD_PRIVMSG, 2, 0, true>;
using command_notice = command_impl<CMD_NOTICE, 2, 0, true>;

/* user queries */

constexpr char CMD_WHO[] = "WHO";
constexpr char CMD_WHOIS[] = "WHOIS";
constexpr char CMD_WHOWAS[] = "WHOWAS";

using command_who = command_impl<CMD_WHO, 0, 2, false>;
using command_whois = command_impl<CMD_WHOIS, 1, 1, false>;
using command_whowas = command_impl<CMD_WHOWAS, 1, 2, false>;

/* misc messages */

constexpr char CMD_KILL[] = "KILL";
constexpr char CMD_PING[] = "PING";
constexpr char CMD_PONG[] = "PONG";
constexpr char CMD_ERROR[] = "ERROR";
constexpr char CMD_AWAY[] = "AWAY";
constexpr char CMD_REHASH[] = "REHASH";
constexpr char CMD_RESTART[] = "RESTART";
constexpr char CMD_SUMMON[] = "SUMMON";
constexpr char CMD_USERS[] = "USERS";
constexpr char CMD_WALLOPS[] = "WALLOPS";
constexpr char CMD_USERHOST[] = "USERHOST";
constexpr char CMD_ISON[] = "ISON";

using command_kill = command_impl<CMD_KILL, 2, 0, true>;
using command_ping = command_impl<CMD_PING, 1, 1, false>;
using command_pong = command_impl<CMD_PONG, 1, 1, false>;
using command_error = command_impl<CMD_ERROR, 1, 0, true>;
using command_away = command_impl<CMD_AWAY, 0, 1, true>;
using command_rehash = command_impl<CMD_REHASH, 0, 0, false>;
using command_restart = command_impl<CMD_RESTART, 0, 0, false>;
using command_summon = command_impl<CMD_SUMMON, 1, 1, false>;
using command_users = command_impl<CMD_USERS, 0, 1, false>;
using command_wallops = command_impl<CMD_WALLOPS, 1, 0, true>;
using command_userhost = command_impl<CMD_USERHOST, 1, 0, true>;
using command_ison = command_impl<CMD_ISON, 1, 0, true>;
}  // namespace protocol
}  // namespace silica

#endif
