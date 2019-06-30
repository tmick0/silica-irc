#include <silica/protocol/deserialize.h>
#include <silica/protocol/commands.h>
#include <silica/protocol/numeric.h>

#include <map>

namespace silica {
namespace protocol {

class factory {
public:
    virtual ~factory() {}
    virtual std::shared_ptr<protobase> create(const std::list<std::string>& from) const = 0;
    virtual prototype getPrototype() const = 0;
};

template <typename Command>
class factory_impl : public factory {
public:
    std::shared_ptr<protobase> create(const std::list<std::string>& from) const override {
        return std::make_shared<Command>(from);
    }

    virtual prototype getPrototype() const override { return Command::Prototype(); }
};

const std::map<std::string, std::shared_ptr<factory>> PROTOTYPE_MAP = {
    // commands
    {command_pass::Prototype().commandString(), std::make_shared<factory_impl<command_pass>>()},
    {command_nick::Prototype().commandString(), std::make_shared<factory_impl<command_nick>>()},
    {command_user::Prototype().commandString(), std::make_shared<factory_impl<command_user>>()},
    {command_oper::Prototype().commandString(), std::make_shared<factory_impl<command_oper>>()},
    {command_quit::Prototype().commandString(), std::make_shared<factory_impl<command_quit>>()},
    {command_join::Prototype().commandString(), std::make_shared<factory_impl<command_join>>()},
    {command_part::Prototype().commandString(), std::make_shared<factory_impl<command_part>>()},
    {command_mode::Prototype().commandString(), std::make_shared<factory_impl<command_mode>>()},
    {command_topic::Prototype().commandString(), std::make_shared<factory_impl<command_topic>>()},
    {command_names::Prototype().commandString(), std::make_shared<factory_impl<command_names>>()},
    {command_list::Prototype().commandString(), std::make_shared<factory_impl<command_list>>()},
    {command_invite::Prototype().commandString(), std::make_shared<factory_impl<command_invite>>()},
    {command_kick::Prototype().commandString(), std::make_shared<factory_impl<command_kick>>()},
    {command_version::Prototype().commandString(), std::make_shared<factory_impl<command_version>>()},
    {command_stats::Prototype().commandString(), std::make_shared<factory_impl<command_stats>>()},
    {command_links::Prototype().commandString(), std::make_shared<factory_impl<command_links>>()},
    {command_time::Prototype().commandString(), std::make_shared<factory_impl<command_time>>()},
    {command_connect::Prototype().commandString(), std::make_shared<factory_impl<command_connect>>()},
    {command_trace::Prototype().commandString(), std::make_shared<factory_impl<command_trace>>()},
    {command_admin::Prototype().commandString(), std::make_shared<factory_impl<command_admin>>()},
    {command_info::Prototype().commandString(), std::make_shared<factory_impl<command_info>>()},
    {command_privmsg::Prototype().commandString(), std::make_shared<factory_impl<command_privmsg>>()},
    {command_notice::Prototype().commandString(), std::make_shared<factory_impl<command_notice>>()},
    {command_who::Prototype().commandString(), std::make_shared<factory_impl<command_who>>()},
    {command_whois::Prototype().commandString(), std::make_shared<factory_impl<command_whois>>()},
    {command_whowas::Prototype().commandString(), std::make_shared<factory_impl<command_whowas>>()},
    {command_kill::Prototype().commandString(), std::make_shared<factory_impl<command_kill>>()},
    {command_ping::Prototype().commandString(), std::make_shared<factory_impl<command_ping>>()},
    {command_pong::Prototype().commandString(), std::make_shared<factory_impl<command_pong>>()},
    {command_error::Prototype().commandString(), std::make_shared<factory_impl<command_error>>()},
    {command_away::Prototype().commandString(), std::make_shared<factory_impl<command_away>>()},
    {command_rehash::Prototype().commandString(), std::make_shared<factory_impl<command_rehash>>()},
    {command_restart::Prototype().commandString(), std::make_shared<factory_impl<command_restart>>()},
    {command_summon::Prototype().commandString(), std::make_shared<factory_impl<command_summon>>()},
    {command_users::Prototype().commandString(), std::make_shared<factory_impl<command_users>>()},
    {command_wallops::Prototype().commandString(), std::make_shared<factory_impl<command_wallops>>()},
    {command_userhost::Prototype().commandString(), std::make_shared<factory_impl<command_userhost>>()},
    {command_ison::Prototype().commandString(), std::make_shared<factory_impl<command_ison>>()},

    // numerics
    {err_nosuchnick::Prototype().commandString(), std::make_shared<factory_impl<err_nosuchnick>>()},
    {err_nosuchserver::Prototype().commandString(), std::make_shared<factory_impl<err_nosuchserver>>()},
    {err_nosuchchannel::Prototype().commandString(), std::make_shared<factory_impl<err_nosuchchannel>>()},
    {err_cannotsendtochan::Prototype().commandString(), std::make_shared<factory_impl<err_cannotsendtochan>>()},
    {err_toomanychannels::Prototype().commandString(), std::make_shared<factory_impl<err_toomanychannels>>()},
    {err_wasnosuchnick::Prototype().commandString(), std::make_shared<factory_impl<err_wasnosuchnick>>()},
    {err_toomanytargets::Prototype().commandString(), std::make_shared<factory_impl<err_toomanytargets>>()},
    {err_noorigin::Prototype().commandString(), std::make_shared<factory_impl<err_noorigin>>()},
    {err_norecipient::Prototype().commandString(), std::make_shared<factory_impl<err_norecipient>>()},
    {err_notexttosend::Prototype().commandString(), std::make_shared<factory_impl<err_notexttosend>>()},
    {err_notoplevel::Prototype().commandString(), std::make_shared<factory_impl<err_notoplevel>>()},
    {err_wildtoplevel::Prototype().commandString(), std::make_shared<factory_impl<err_wildtoplevel>>()},
    {err_unknowncommand::Prototype().commandString(), std::make_shared<factory_impl<err_unknowncommand>>()},
    {err_nomotd::Prototype().commandString(), std::make_shared<factory_impl<err_nomotd>>()},
    {err_noadmininfo::Prototype().commandString(), std::make_shared<factory_impl<err_noadmininfo>>()},
    {err_fileerror::Prototype().commandString(), std::make_shared<factory_impl<err_fileerror>>()},
    {err_nonicknamegiven::Prototype().commandString(), std::make_shared<factory_impl<err_nonicknamegiven>>()},
    {err_erroneusnickname::Prototype().commandString(), std::make_shared<factory_impl<err_erroneusnickname>>()},
    {err_nicknameinuse::Prototype().commandString(), std::make_shared<factory_impl<err_nicknameinuse>>()},
    {err_nickcollision::Prototype().commandString(), std::make_shared<factory_impl<err_nickcollision>>()},
    {err_usernotinchannel::Prototype().commandString(), std::make_shared<factory_impl<err_usernotinchannel>>()},
    {err_notonchannel::Prototype().commandString(), std::make_shared<factory_impl<err_notonchannel>>()},
    {err_useronchannel::Prototype().commandString(), std::make_shared<factory_impl<err_useronchannel>>()},
    {err_nologin::Prototype().commandString(), std::make_shared<factory_impl<err_nologin>>()},
    {err_summondisabled::Prototype().commandString(), std::make_shared<factory_impl<err_summondisabled>>()},
    {err_usersdisabled::Prototype().commandString(), std::make_shared<factory_impl<err_usersdisabled>>()},
    {err_notregistered::Prototype().commandString(), std::make_shared<factory_impl<err_notregistered>>()},
    {err_needmoreparams::Prototype().commandString(), std::make_shared<factory_impl<err_needmoreparams>>()},
    {err_alreadyregistred::Prototype().commandString(), std::make_shared<factory_impl<err_alreadyregistred>>()},
    {err_nopermforhost::Prototype().commandString(), std::make_shared<factory_impl<err_nopermforhost>>()},
    {err_passwdmismatch::Prototype().commandString(), std::make_shared<factory_impl<err_passwdmismatch>>()},
    {err_yourebannedcreep::Prototype().commandString(), std::make_shared<factory_impl<err_yourebannedcreep>>()},
    {err_keyset::Prototype().commandString(), std::make_shared<factory_impl<err_keyset>>()},
    {err_channelisfull::Prototype().commandString(), std::make_shared<factory_impl<err_channelisfull>>()},
    {err_unknownmode::Prototype().commandString(), std::make_shared<factory_impl<err_unknownmode>>()},
    {err_inviteonlychan::Prototype().commandString(), std::make_shared<factory_impl<err_inviteonlychan>>()},
    {err_bannedfromchan::Prototype().commandString(), std::make_shared<factory_impl<err_bannedfromchan>>()},
    {err_badchannelkey::Prototype().commandString(), std::make_shared<factory_impl<err_badchannelkey>>()},
    {err_noprivileges::Prototype().commandString(), std::make_shared<factory_impl<err_noprivileges>>()},
    {err_chanoprivsneeded::Prototype().commandString(), std::make_shared<factory_impl<err_chanoprivsneeded>>()},
    {err_cantkillserver::Prototype().commandString(), std::make_shared<factory_impl<err_cantkillserver>>()},
    {err_nooperhost::Prototype().commandString(), std::make_shared<factory_impl<err_nooperhost>>()},
    {err_umodeunknownflag::Prototype().commandString(), std::make_shared<factory_impl<err_umodeunknownflag>>()},
    {err_usersdontmatch::Prototype().commandString(), std::make_shared<factory_impl<err_usersdontmatch>>()},
    {rpl_userhost::Prototype().commandString(), std::make_shared<factory_impl<rpl_userhost>>()},
    {rpl_ison::Prototype().commandString(), std::make_shared<factory_impl<rpl_ison>>()},
    {rpl_away::Prototype().commandString(), std::make_shared<factory_impl<rpl_away>>()},
    {rpl_unaway::Prototype().commandString(), std::make_shared<factory_impl<rpl_unaway>>()},
    {rpl_nowaway::Prototype().commandString(), std::make_shared<factory_impl<rpl_nowaway>>()},
    {rpl_whoisuser::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoisuser>>()},
    {rpl_whoisserver::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoisserver>>()},
    {rpl_whoisoperator::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoisoperator>>()},
    {rpl_whoisidle::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoisidle>>()},
    {rpl_endofwhois::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofwhois>>()},
    {rpl_whoischannels::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoischannels>>()},
    {rpl_whowasuser::Prototype().commandString(), std::make_shared<factory_impl<rpl_whowasuser>>()},
    {rpl_endofwhowas::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofwhowas>>()},
    {rpl_liststart::Prototype().commandString(), std::make_shared<factory_impl<rpl_liststart>>()},
    {rpl_list::Prototype().commandString(), std::make_shared<factory_impl<rpl_list>>()},
    {rpl_listend::Prototype().commandString(), std::make_shared<factory_impl<rpl_listend>>()},
    {rpl_channelmodeis::Prototype().commandString(), std::make_shared<factory_impl<rpl_channelmodeis>>()},
    {rpl_notopic::Prototype().commandString(), std::make_shared<factory_impl<rpl_notopic>>()},
    {rpl_topic::Prototype().commandString(), std::make_shared<factory_impl<rpl_topic>>()},
    {rpl_inviting::Prototype().commandString(), std::make_shared<factory_impl<rpl_inviting>>()},
    {rpl_summoning::Prototype().commandString(), std::make_shared<factory_impl<rpl_summoning>>()},
    {rpl_version::Prototype().commandString(), std::make_shared<factory_impl<rpl_version>>()},
    {rpl_whoreply::Prototype().commandString(), std::make_shared<factory_impl<rpl_whoreply>>()},
    {rpl_endofwho::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofwho>>()},
    {rpl_namreply::Prototype().commandString(), std::make_shared<factory_impl<rpl_namreply>>()},
    {rpl_endofnames::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofnames>>()},
    {rpl_links::Prototype().commandString(), std::make_shared<factory_impl<rpl_links>>()},
    {rpl_endoflinks::Prototype().commandString(), std::make_shared<factory_impl<rpl_endoflinks>>()},
    {rpl_banlist::Prototype().commandString(), std::make_shared<factory_impl<rpl_banlist>>()},
    {rpl_endofbanlist::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofbanlist>>()},
    {rpl_info::Prototype().commandString(), std::make_shared<factory_impl<rpl_info>>()},
    {rpl_endofinfo::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofinfo>>()},
    {rpl_motdstart::Prototype().commandString(), std::make_shared<factory_impl<rpl_motdstart>>()},
    {rpl_motd::Prototype().commandString(), std::make_shared<factory_impl<rpl_motd>>()},
    {rpl_endofmotd::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofmotd>>()},
    {rpl_youreoper::Prototype().commandString(), std::make_shared<factory_impl<rpl_youreoper>>()},
    {rpl_rehashing::Prototype().commandString(), std::make_shared<factory_impl<rpl_rehashing>>()},
    {rpl_time::Prototype().commandString(), std::make_shared<factory_impl<rpl_time>>()},
    {rpl_usersstart::Prototype().commandString(), std::make_shared<factory_impl<rpl_usersstart>>()},
    {rpl_users::Prototype().commandString(), std::make_shared<factory_impl<rpl_users>>()},
    {rpl_endofusers::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofusers>>()},
    {rpl_nousers::Prototype().commandString(), std::make_shared<factory_impl<rpl_nousers>>()},
    {rpl_tracelink::Prototype().commandString(), std::make_shared<factory_impl<rpl_tracelink>>()},
    {rpl_traceconnecting::Prototype().commandString(), std::make_shared<factory_impl<rpl_traceconnecting>>()},
    {rpl_tracehandshake::Prototype().commandString(), std::make_shared<factory_impl<rpl_tracehandshake>>()},
    {rpl_traceunknown::Prototype().commandString(), std::make_shared<factory_impl<rpl_traceunknown>>()},
    {rpl_traceoperator::Prototype().commandString(), std::make_shared<factory_impl<rpl_traceoperator>>()},
    {rpl_traceuser::Prototype().commandString(), std::make_shared<factory_impl<rpl_traceuser>>()},
    {rpl_traceserver::Prototype().commandString(), std::make_shared<factory_impl<rpl_traceserver>>()},
    {rpl_tracenewtype::Prototype().commandString(), std::make_shared<factory_impl<rpl_tracenewtype>>()},
    {rpl_tracelog::Prototype().commandString(), std::make_shared<factory_impl<rpl_tracelog>>()},
    {rpl_statslinkinfo::Prototype().commandString(), std::make_shared<factory_impl<rpl_statslinkinfo>>()},
    {rpl_statscommands::Prototype().commandString(), std::make_shared<factory_impl<rpl_statscommands>>()},
    {rpl_statscline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statscline>>()},
    {rpl_statsnline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statsnline>>()},
    {rpl_statsiline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statsiline>>()},
    {rpl_statskline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statskline>>()},
    {rpl_statsyline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statsyline>>()},
    {rpl_endofstats::Prototype().commandString(), std::make_shared<factory_impl<rpl_endofstats>>()},
    {rpl_statslline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statslline>>()},
    {rpl_statsuptime::Prototype().commandString(), std::make_shared<factory_impl<rpl_statsuptime>>()},
    {rpl_statsoline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statsoline>>()},
    {rpl_statshline::Prototype().commandString(), std::make_shared<factory_impl<rpl_statshline>>()},
    {rpl_umodeis::Prototype().commandString(), std::make_shared<factory_impl<rpl_umodeis>>()},
    {rpl_luserclient::Prototype().commandString(), std::make_shared<factory_impl<rpl_luserclient>>()},
    {rpl_luserop::Prototype().commandString(), std::make_shared<factory_impl<rpl_luserop>>()},
    {rpl_luserunknown::Prototype().commandString(), std::make_shared<factory_impl<rpl_luserunknown>>()},
    {rpl_luserchannels::Prototype().commandString(), std::make_shared<factory_impl<rpl_luserchannels>>()},
    {rpl_luserme::Prototype().commandString(), std::make_shared<factory_impl<rpl_luserme>>()},
    {rpl_adminme::Prototype().commandString(), std::make_shared<factory_impl<rpl_adminme>>()},
    {rpl_adminloc1::Prototype().commandString(), std::make_shared<factory_impl<rpl_adminloc1>>()},
    {rpl_adminloc2::Prototype().commandString(), std::make_shared<factory_impl<rpl_adminloc2>>()},
    {rpl_adminemail::Prototype().commandString(), std::make_shared<factory_impl<rpl_adminemail>>()}

};

std::shared_ptr<protobase> deserialize(const std::string& command) {
    size_t last_space = 0;
    size_t next_space = command.find(' ');

    if (next_space == std::string::npos) {
        make_error("Could not deserialize command because no delimiter was found: '" << command << "'");
    }

    // TODO: make the source available in the returned message
    if (command[last_space] == ':') {
        const std::string source(command.substr(last_space, next_space - last_space));
        last_space = next_space + 1;
        next_space = command.find(' ', last_space);
    }

    const std::string cmd(command.substr(last_space, next_space - last_space));

    auto factory_it = PROTOTYPE_MAP.find(cmd);
    if (factory_it == PROTOTYPE_MAP.end()) {
        make_error("Unknown command: '" << cmd << "'");
    }

    const auto factory = factory_it->second;
    const auto prototype = factory->getPrototype();

    std::list<std::string> args;

    while (next_space != std::string::npos) {
        size_t start = next_space + 1;

        std::string next_substring;

        // HACK: made parsing of last variable-length argument less strict
        if (start < command.size() && command.at(start) == ':') {
            next_space = command.find_last_not_of(" \n");
            next_substring = command.substr(start + 1);
        } else {
            next_space = command.find_first_of(" \n", start);
            next_substring = command.substr(start, next_space - start);
        }

        if (!next_substring.empty()) {
            args.emplace_back(next_substring);
        }
    }

    return factory->create(args);
}

}  // namespace protocol
}  // namespace silica