#include "commands.h"

#include <map>
#include "common/error.h"

namespace silica {
namespace protocol {

namespace {
class command_factory {
public:
    virtual std::shared_ptr<command_base> create(const std::list<std::string>& from) const = 0;
    virtual command_prototype prototype() const = 0;
};

template <typename Command>
class command_factory_impl : public command_factory {
public:
    std::shared_ptr<command_base> create(const std::list<std::string>& from) const override {
        return std::make_shared<Command>(from);
    }

    virtual command_prototype prototype() const override { return Command::Prototype(); }
};
}

const std::map<std::string, std::shared_ptr<command_factory>> PROTOTYPE_MAP = {
    {command_nick::Prototype().commandString(), std::make_shared<command_factory_impl<command_nick>>()},
    {command_user::Prototype().commandString(), std::make_shared<command_factory_impl<command_user>>()},
    {command_oper::Prototype().commandString(), std::make_shared<command_factory_impl<command_oper>>()},
    {command_quit::Prototype().commandString(), std::make_shared<command_factory_impl<command_quit>>()},
    {command_join::Prototype().commandString(), std::make_shared<command_factory_impl<command_join>>()},
    {command_part::Prototype().commandString(), std::make_shared<command_factory_impl<command_part>>()},
    {command_mode::Prototype().commandString(), std::make_shared<command_factory_impl<command_mode>>()},
    {command_topic::Prototype().commandString(), std::make_shared<command_factory_impl<command_topic>>()},
    {command_names::Prototype().commandString(), std::make_shared<command_factory_impl<command_names>>()},
    {command_list::Prototype().commandString(), std::make_shared<command_factory_impl<command_list>>()},
    {command_invite::Prototype().commandString(), std::make_shared<command_factory_impl<command_invite>>()},
    {command_kick::Prototype().commandString(), std::make_shared<command_factory_impl<command_kick>>()},
    {command_version::Prototype().commandString(), std::make_shared<command_factory_impl<command_version>>()},
    {command_stats::Prototype().commandString(), std::make_shared<command_factory_impl<command_stats>>()},
    {command_links::Prototype().commandString(), std::make_shared<command_factory_impl<command_links>>()},
    {command_time::Prototype().commandString(), std::make_shared<command_factory_impl<command_time>>()},
    {command_connect::Prototype().commandString(), std::make_shared<command_factory_impl<command_connect>>()},
    {command_trace::Prototype().commandString(), std::make_shared<command_factory_impl<command_trace>>()},
    {command_admin::Prototype().commandString(), std::make_shared<command_factory_impl<command_admin>>()},
    {command_info::Prototype().commandString(), std::make_shared<command_factory_impl<command_info>>()},
    {command_privmsg::Prototype().commandString(), std::make_shared<command_factory_impl<command_privmsg>>()},
    {command_notice::Prototype().commandString(), std::make_shared<command_factory_impl<command_notice>>()},
    {command_who::Prototype().commandString(), std::make_shared<command_factory_impl<command_who>>()},
    {command_whois::Prototype().commandString(), std::make_shared<command_factory_impl<command_whois>>()},
    {command_whowas::Prototype().commandString(), std::make_shared<command_factory_impl<command_whowas>>()},
    {command_kill::Prototype().commandString(), std::make_shared<command_factory_impl<command_kill>>()},
    {command_ping::Prototype().commandString(), std::make_shared<command_factory_impl<command_ping>>()},
    {command_pong::Prototype().commandString(), std::make_shared<command_factory_impl<command_pong>>()},
    {command_error::Prototype().commandString(), std::make_shared<command_factory_impl<command_error>>()},
    {command_away::Prototype().commandString(), std::make_shared<command_factory_impl<command_away>>()},
    {command_rehash::Prototype().commandString(), std::make_shared<command_factory_impl<command_rehash>>()},
    {command_restart::Prototype().commandString(), std::make_shared<command_factory_impl<command_restart>>()},
    {command_summon::Prototype().commandString(), std::make_shared<command_factory_impl<command_summon>>()},
    {command_users::Prototype().commandString(), std::make_shared<command_factory_impl<command_users>>()},
    {command_wallops::Prototype().commandString(), std::make_shared<command_factory_impl<command_wallops>>()},
    {command_userhost::Prototype().commandString(), std::make_shared<command_factory_impl<command_userhost>>()},
    {command_ison::Prototype().commandString(), std::make_shared<command_factory_impl<command_ison>>()}};

bool command_base::operator==(const command_base& other) const {
    return prototype() == other.prototype() && m_args == other.m_args;
}

bool command_prototype::operator==(const command_prototype& other) const {
    return std::string{m_commandString} ==
           std::string{
               other.m_commandString};  // should be sufficient unless someones goes playing games with the types
}

const char* command_prototype::commandString() const { return m_commandString; }

bool command_prototype::lastArgVarLen() const { return m_lastArgVarLen; }

int command_prototype::numOptional() const { return m_numOptional; }

int command_prototype::numRequired() const { return m_numRequired; }

std::shared_ptr<command_base> deserialize_command(const std::string& command) {
    size_t next_space = command.find(' ');

    if (next_space == std::string::npos) {
        make_error("Could not deserialize command because no delimiter was found: '" << command << "'");
    }

    const std::string cmd(command.substr(0, next_space));

    auto factory_it = PROTOTYPE_MAP.find(cmd);
    if (factory_it == PROTOTYPE_MAP.end()) {
        make_error("Unknown command: '" << cmd << "'");
    }

    const auto factory = factory_it->second;
    const auto prototype = factory->prototype();

    std::list<std::string> args;

    while (next_space != std::string::npos) {
        size_t start = next_space + 1;

        if (prototype.lastArgVarLen() &&
            args.size() == static_cast<size_t>(prototype.numRequired() + prototype.numOptional() - 1)) {
            next_space = command.find_last_not_of(" \n") + 1;
            start += 1;
        } else {
            next_space = command.find_first_of(" \n", start);
        }

        const std::string next_substring{command, start, next_space - start};

        if (!next_substring.empty()) {
            args.emplace_back(command, start, next_space - start);
        }
    }

    return factory->create(args);
}
}
}
