#ifndef numeric_h_
#define numeric_h_

#include <list>
#include <string>

namespace silica {
namespace protocol {

class numeric_base {
public:
};

template <int NumericCode, const char* SymbolicName, int NumArgs>
class numeric_impl : public numeric_base {
public:
    template <typename Container>
    numeric_impl(Container const& args) : m_args(args.begin(), args.end()) {}

private:
    std::list<std::string> m_args;
};

/* error replies */

constexpr int NUM_ERR_NOSUCHNICK = 401;
constexpr char SYM_ERR_NOSUCHNICK[] = "ERR_NOSUCHNICK";
using err_nosuchnick = numeric_impl<NUM_ERR_NOSUCHNICK, SYM_ERR_NOSUCHNICK, 1>;

constexpr int NUM_ERR_NOSUCHSERVER = 402;
constexpr char SYM_ERR_NOSUCHSERVER[] = "ERR_NOSUCHSERVER";
using err_nosuchserver = numeric_impl<NUM_ERR_NOSUCHSERVER, SYM_ERR_NOSUCHSERVER, 1>;

constexpr int NUM_ERR_NOSUCHCHANNEL = 403;
constexpr char SYM_ERR_NOSUCHCHANNEL[] = "ERR_NOSUCHCHANNEL";
using err_nosuchchannel = numeric_impl<NUM_ERR_NOSUCHCHANNEL, SYM_ERR_NOSUCHCHANNEL, 1>;

constexpr int NUM_ERR_CANNOTSENDTOCHAN = 404;
constexpr char SYM_ERR_CANNOTSENDTOCHAN[] = "ERR_CANNOTSENDTOCHAN";
using err_cannotsendtochan = numeric_impl<NUM_ERR_CANNOTSENDTOCHAN, SYM_ERR_CANNOTSENDTOCHAN, 1>;

constexpr int NUM_ERR_TOOMANYCHANNELS = 405;
constexpr char SYM_ERR_TOOMANYCHANNELS[] = "ERR_TOOMANYCHANNELS";
using err_toomanychannels = numeric_impl<NUM_ERR_TOOMANYCHANNELS, SYM_ERR_TOOMANYCHANNELS, 1>;

constexpr int NUM_ERR_WASNOSUCHNICK = 406;
constexpr char SYM_ERR_WASNOSUCHNICK[] = "ERR_WASNOSUCHNICK";
using err_wasnosuchnick = numeric_impl<NUM_ERR_WASNOSUCHNICK, SYM_ERR_WASNOSUCHNICK, 1>;

constexpr int NUM_ERR_TOOMANYTARGETS = 407;
constexpr char SYM_ERR_TOOMANYTARGETS[] = "ERR_TOOMANYTARGETS";
using err_toomanytargets = numeric_impl<NUM_ERR_TOOMANYTARGETS, SYM_ERR_TOOMANYTARGETS, 1>;

constexpr int NUM_ERR_NOORIGIN = 409;
constexpr char SYM_ERR_NOORIGIN[] = "ERR_NOORIGIN";
using err_noorigin = numeric_impl<NUM_ERR_NOORIGIN, SYM_ERR_NOORIGIN, 0>;

constexpr int NUM_ERR_NORECIPIENT = 411;
constexpr char SYM_ERR_NORECIPIENT[] = "ERR_NORECIPIENT";
using err_norecipient = numeric_impl<NUM_ERR_NORECIPIENT, SYM_ERR_NORECIPIENT, 0>;

constexpr int NUM_ERR_NOTEXTTOSEND = 412;
constexpr char SYM_ERR_NOTEXTTOSEND[] = "ERR_NOTEXTTOSEND";
using err_notexttosend = numeric_impl<NUM_ERR_NOTEXTTOSEND, SYM_ERR_NOTEXTTOSEND, 0>;

constexpr int NUM_ERR_NOTOPLEVEL = 413;
constexpr char SYM_ERR_NOTOPLEVEL[] = "ERR_NOTOPLEVEL";
using err_notoplevel = numeric_impl<NUM_ERR_NOTOPLEVEL, SYM_ERR_NOTOPLEVEL, 1>;

constexpr int NUM_ERR_WILDTOPLEVEL = 414;
constexpr char SYM_ERR_WILDTOPLEVEL[] = "ERR_WILDTOPLEVEL";
using err_wildtoplevel = numeric_impl<NUM_ERR_WILDTOPLEVEL, SYM_ERR_WILDTOPLEVEL, 1>;

constexpr int NUM_ERR_UNKNOWNCOMMAND = 421;
constexpr char SYM_ERR_UNKNOWNCOMMAND[] = "ERR_UNKNOWNCOMMAND";
using err_unknowncommand = numeric_impl<NUM_ERR_UNKNOWNCOMMAND, SYM_ERR_UNKNOWNCOMMAND, 1>;

constexpr int NUM_ERR_NOMOTD = 422;
constexpr char SYM_ERR_NOMOTD[] = "ERR_NOMOTD";
using err_nomotd = numeric_impl<NUM_ERR_NOMOTD, SYM_ERR_NOMOTD, 0>;

constexpr int NUM_ERR_NOADMININFO = 423;
constexpr char SYM_ERR_NOADMININFO[] = "ERR_NOADMININFO";
using err_noadmininfo = numeric_impl<NUM_ERR_NOADMININFO, SYM_ERR_NOADMININFO, 1>;

constexpr int NUM_ERR_FILEERROR = 424;
constexpr char SYM_ERR_FILEERROR[] = "ERR_FILEERROR";
using err_fileerror = numeric_impl<NUM_ERR_FILEERROR, SYM_ERR_FILEERROR, 0>;

constexpr int NUM_ERR_NONICKNAMEGIVEN = 431;
constexpr char SYM_ERR_NONICKNAMEGIVEN[] = "ERR_NONICKNAMEGIVEN";
using err_nonicknamegiven = numeric_impl<NUM_ERR_NONICKNAMEGIVEN, SYM_ERR_NONICKNAMEGIVEN, 0>;

constexpr int NUM_ERR_ERRONEUSNICKNAME = 432;
constexpr char SYM_ERR_ERRONEUSNICKNAME[] = "ERR_ERRONEUSNICKNAME";
using err_erroneusnickname = numeric_impl<NUM_ERR_ERRONEUSNICKNAME, SYM_ERR_ERRONEUSNICKNAME, 1>;

constexpr int NUM_ERR_NICKNAMEINUSE = 433;
constexpr char SYM_ERR_NICKNAMEINUSE[] = "ERR_NICKNAMEINUSE";
using err_nicknameinuse = numeric_impl<NUM_ERR_NICKNAMEINUSE, SYM_ERR_NICKNAMEINUSE, 1>;

constexpr int NUM_ERR_NICKCOLLISION = 436;
constexpr char SYM_ERR_NICKCOLLISION[] = "ERR_NICKCOLLISION";
using err_nickcollision = numeric_impl<NUM_ERR_NICKCOLLISION, SYM_ERR_NICKCOLLISION, 1>;

constexpr int NUM_ERR_USERNOTINCHANNEL = 441;
constexpr char SYM_ERR_USERNOTINCHANNEL[] = "ERR_USERNOTINCHANNEL";
using err_usernotinchannel = numeric_impl<NUM_ERR_USERNOTINCHANNEL, SYM_ERR_USERNOTINCHANNEL, 2>;

constexpr int NUM_ERR_NOTONCHANNEL = 442;
constexpr char SYM_ERR_NOTONCHANNEL[] = "ERR_NOTONCHANNEL";
using err_notonchannel = numeric_impl<NUM_ERR_NOTONCHANNEL, SYM_ERR_NOTONCHANNEL, 1>;

constexpr int NUM_ERR_USERONCHANNEL = 443;
constexpr char SYM_ERR_USERONCHANNEL[] = "ERR_USERONCHANNEL";
using err_useronchannel = numeric_impl<NUM_ERR_USERONCHANNEL, SYM_ERR_USERONCHANNEL, 2>;

constexpr int NUM_ERR_NOLOGIN = 444;
constexpr char SYM_ERR_NOLOGIN[] = "ERR_NOLOGIN";
using err_nologin = numeric_impl<NUM_ERR_NOLOGIN, SYM_ERR_NOLOGIN, 1>;

constexpr int NUM_ERR_SUMMONDISABLED = 445;
constexpr char SYM_ERR_SUMMONDISABLED[] = "ERR_SUMMONDISABLED";
using err_summondisabled = numeric_impl<NUM_ERR_SUMMONDISABLED, SYM_ERR_SUMMONDISABLED, 0>;

constexpr int NUM_ERR_USERSDISABLED = 446;
constexpr char SYM_ERR_USERSDISABLED[] = "ERR_USERSDISABLED";
using err_usersdisabled = numeric_impl<NUM_ERR_USERSDISABLED, SYM_ERR_USERSDISABLED, 0>;

constexpr int NUM_ERR_NOTREGISTERED = 451;
constexpr char SYM_ERR_NOTREGISTERED[] = "ERR_NOTREGISTERED";
using err_notregistered = numeric_impl<NUM_ERR_NOTREGISTERED, SYM_ERR_NOTREGISTERED, 0>;

constexpr int NUM_ERR_NEEDMOREPARAMS = 461;
constexpr char SYM_ERR_NEEDMOREPARAMS[] = "ERR_NEEDMOREPARAMS";
using err_needmoreparams = numeric_impl<NUM_ERR_NEEDMOREPARAMS, SYM_ERR_NEEDMOREPARAMS, 1>;

constexpr int NUM_ERR_ALREADYREGISTRED = 462;
constexpr char SYM_ERR_ALREADYREGISTRED[] = "ERR_ALREADYREGISTRED";
using err_alreadyregistred = numeric_impl<NUM_ERR_ALREADYREGISTRED, SYM_ERR_ALREADYREGISTRED, 0>;

constexpr int NUM_ERR_NOPERMFORHOST = 463;
constexpr char SYM_ERR_NOPERMFORHOST[] = "ERR_NOPERMFORHOST";
using err_nopermforhost = numeric_impl<NUM_ERR_NOPERMFORHOST, SYM_ERR_NOPERMFORHOST, 0>;

constexpr int NUM_ERR_PASSWDMISMATCH = 464;
constexpr char SYM_ERR_PASSWDMISMATCH[] = "ERR_PASSWDMISMATCH";
using err_passwdmismatch = numeric_impl<NUM_ERR_PASSWDMISMATCH, SYM_ERR_PASSWDMISMATCH, 0>;

constexpr int NUM_ERR_YOUREBANNEDCREEP = 465;
constexpr char SYM_ERR_YOUREBANNEDCREEP[] = "ERR_YOUREBANNEDCREEP";
using err_yourebannedcreep = numeric_impl<NUM_ERR_YOUREBANNEDCREEP, SYM_ERR_YOUREBANNEDCREEP, 0>;

constexpr int NUM_ERR_KEYSET = 467;
constexpr char SYM_ERR_KEYSET[] = "ERR_KEYSET";
using err_keyset = numeric_impl<NUM_ERR_KEYSET, SYM_ERR_KEYSET, 1>;

constexpr int NUM_ERR_CHANNELISFULL = 471;
constexpr char SYM_ERR_CHANNELISFULL[] = "ERR_CHANNELISFULL";
using err_channelisfull = numeric_impl<NUM_ERR_CHANNELISFULL, SYM_ERR_CHANNELISFULL, 1>;

constexpr int NUM_ERR_UNKNOWNMODE = 472;
constexpr char SYM_ERR_UNKNOWNMODE[] = "ERR_UNKNOWNMODE";
using err_unknownmode = numeric_impl<NUM_ERR_UNKNOWNMODE, SYM_ERR_UNKNOWNMODE, 1>;

constexpr int NUM_ERR_INVITEONLYCHAN = 473;
constexpr char SYM_ERR_INVITEONLYCHAN[] = "ERR_INVITEONLYCHAN";
using err_inviteonlychan = numeric_impl<NUM_ERR_INVITEONLYCHAN, SYM_ERR_INVITEONLYCHAN, 1>;

constexpr int NUM_ERR_BANNEDFROMCHAN = 474;
constexpr char SYM_ERR_BANNEDFROMCHAN[] = "ERR_BANNEDFROMCHAN";
using err_bannedfromchan = numeric_impl<NUM_ERR_BANNEDFROMCHAN, SYM_ERR_BANNEDFROMCHAN, 1>;

constexpr int NUM_ERR_BADCHANNELKEY = 475;
constexpr char SYM_ERR_BADCHANNELKEY[] = "ERR_BADCHANNELKEY";
using err_badchannelkey = numeric_impl<NUM_ERR_BADCHANNELKEY, SYM_ERR_BADCHANNELKEY, 1>;

constexpr int NUM_ERR_NOPRIVILEGES = 481;
constexpr char SYM_ERR_NOPRIVILEGES[] = "ERR_NOPRIVILEGES";
using err_noprivileges = numeric_impl<NUM_ERR_NOPRIVILEGES, SYM_ERR_NOPRIVILEGES, 0>;

constexpr int NUM_ERR_CHANOPRIVSNEEDED = 482;
constexpr char SYM_ERR_CHANOPRIVSNEEDED[] = "ERR_CHANOPRIVSNEEDED";
using err_chanoprivsneeded = numeric_impl<NUM_ERR_CHANOPRIVSNEEDED, SYM_ERR_CHANOPRIVSNEEDED, 1>;

constexpr int NUM_ERR_CANTKILLSERVER = 483;
constexpr char SYM_ERR_CANTKILLSERVER[] = "ERR_CANTKILLSERVER";
using err_cantkillserver = numeric_impl<NUM_ERR_CANTKILLSERVER, SYM_ERR_CANTKILLSERVER, 0>;

constexpr int NUM_ERR_NOOPERHOST = 491;
constexpr char SYM_ERR_NOOPERHOST[] = "ERR_NOOPERHOST";
using err_nooperhost = numeric_impl<NUM_ERR_NOOPERHOST, SYM_ERR_NOOPERHOST, 0>;

constexpr int NUM_ERR_UMODEUNKNOWNFLAG = 501;
constexpr char SYM_ERR_UMODEUNKNOWNFLAG[] = "ERR_UMODEUNKNOWNFLAG";
using err_umodeunknownflag = numeric_impl<NUM_ERR_UMODEUNKNOWNFLAG, SYM_ERR_UMODEUNKNOWNFLAG, 0>;

constexpr int NUM_ERR_USERSDONTMATCH = 502;
constexpr char SYM_ERR_USERSDONTMATCH[] = "ERR_USERSDONTMATCH";
using err_usersdontmatch = numeric_impl<NUM_ERR_USERSDONTMATCH, SYM_ERR_USERSDONTMATCH, 0>;

/* replies */

constexpr int NUM_RPL_USERHOST = 302;
constexpr char SYM_RPL_USERHOST[] = "RPL_USERHOST";
using rpl_userhost = numeric_impl<NUM_RPL_USERHOST, SYM_RPL_USERHOST, 0>;

constexpr int NUM_RPL_ISON = 303;
constexpr char SYM_RPL_ISON[] = "RPL_ISON";
using rpl_ison = numeric_impl<NUM_RPL_ISON, SYM_RPL_ISON, 0>;

constexpr int NUM_RPL_AWAY = 301;
constexpr char SYM_RPL_AWAY[] = "RPL_AWAY";
using rpl_away = numeric_impl<NUM_RPL_AWAY, SYM_RPL_AWAY, 1>;

constexpr int NUM_RPL_UNAWAY = 305;
constexpr char SYM_RPL_UNAWAY[] = "RPL_UNAWAY";
using rpl_unaway = numeric_impl<NUM_RPL_UNAWAY, SYM_RPL_UNAWAY, 0>;

constexpr int NUM_RPL_NOWAWAY = 306;
constexpr char SYM_RPL_NOWAWAY[] = "RPL_NOWAWAY";
using rpl_nowaway = numeric_impl<NUM_RPL_NOWAWAY, SYM_RPL_NOWAWAY, 0>;

constexpr int NUM_RPL_WHOISUSER = 311;
constexpr char SYM_RPL_WHOISUSER[] = "RPL_WHOISUSER";
using rpl_whoisuser = numeric_impl<NUM_RPL_WHOISUSER, SYM_RPL_WHOISUSER, 4>;

constexpr int NUM_RPL_WHOISSERVER = 312;
constexpr char SYM_RPL_WHOISSERVER[] = "RPL_WHOISSERVER";
using rpl_whoisserver = numeric_impl<NUM_RPL_WHOISSERVER, SYM_RPL_WHOISSERVER, 2>;

constexpr int NUM_RPL_WHOISOPERATOR = 313;
constexpr char SYM_RPL_WHOISOPERATOR[] = "RPL_WHOISOPERATOR";
using rpl_whoisoperator = numeric_impl<NUM_RPL_WHOISOPERATOR, SYM_RPL_WHOISOPERATOR, 1>;

constexpr int NUM_RPL_WHOISIDLE = 317;
constexpr char SYM_RPL_WHOISIDLE[] = "RPL_WHOISIDLE";
using rpl_whoisidle = numeric_impl<NUM_RPL_WHOISIDLE, SYM_RPL_WHOISIDLE, 2>;

constexpr int NUM_RPL_ENDOFWHOIS = 318;
constexpr char SYM_RPL_ENDOFWHOIS[] = "RPL_ENDOFWHOIS";
using rpl_endofwhois = numeric_impl<NUM_RPL_ENDOFWHOIS, SYM_RPL_ENDOFWHOIS, 1>;

constexpr int NUM_RPL_WHOISCHANNELS = 319;
constexpr char SYM_RPL_WHOISCHANNELS[] = "RPL_WHOISCHANNELS";
using rpl_whoischannels = numeric_impl<NUM_RPL_WHOISCHANNELS, SYM_RPL_WHOISCHANNELS, 1>;

constexpr int NUM_RPL_WHOWASUSER = 314;
constexpr char SYM_RPL_WHOWASUSER[] = "RPL_WHOWASUSER";
using rpl_whowasuser = numeric_impl<NUM_RPL_WHOWASUSER, SYM_RPL_WHOWASUSER, 4>;

constexpr int NUM_RPL_ENDOFWHOWAS = 369;
constexpr char SYM_RPL_ENDOFWHOWAS[] = "RPL_ENDOFWHOWAS";
using rpl_endofwhowas = numeric_impl<NUM_RPL_ENDOFWHOWAS, SYM_RPL_ENDOFWHOWAS, 1>;

constexpr int NUM_RPL_LISTSTART = 321;
constexpr char SYM_RPL_LISTSTART[] = "RPL_LISTSTART";
using rpl_liststart = numeric_impl<NUM_RPL_LISTSTART, SYM_RPL_LISTSTART, 1>;

constexpr int NUM_RPL_LIST = 322;
constexpr char SYM_RPL_LIST[] = "RPL_LIST";
using rpl_list = numeric_impl<NUM_RPL_LIST, SYM_RPL_LIST, 2>;

constexpr int NUM_RPL_LISTEND = 323;
constexpr char SYM_RPL_LISTEND[] = "RPL_LISTEND";
using rpl_listend = numeric_impl<NUM_RPL_LISTEND, SYM_RPL_LISTEND, 1>;

constexpr int NUM_RPL_CHANNELMODEIS = 324;
constexpr char SYM_RPL_CHANNELMODEIS[] = "RPL_CHANNELMODEIS";
using rpl_channelmodeis = numeric_impl<NUM_RPL_CHANNELMODEIS, SYM_RPL_CHANNELMODEIS, 3>;

constexpr int NUM_RPL_NOTOPIC = 331;
constexpr char SYM_RPL_NOTOPIC[] = "RPL_NOTOPIC";
using rpl_notopic = numeric_impl<NUM_RPL_NOTOPIC, SYM_RPL_NOTOPIC, 1>;

constexpr int NUM_RPL_TOPIC = 332;
constexpr char SYM_RPL_TOPIC[] = "RPL_TOPIC";
using rpl_topic = numeric_impl<NUM_RPL_TOPIC, SYM_RPL_TOPIC, 1>;

constexpr int NUM_RPL_INVITING = 341;
constexpr char SYM_RPL_INVITING[] = "RPL_INVITING";
using rpl_inviting = numeric_impl<NUM_RPL_INVITING, SYM_RPL_INVITING, 1>;

constexpr int NUM_RPL_SUMMONING = 342;
constexpr char SYM_RPL_SUMMONING[] = "RPL_SUMMONING";
using rpl_summoning = numeric_impl<NUM_RPL_SUMMONING, SYM_RPL_SUMMONING, 1>;

constexpr int NUM_RPL_VERSION = 351;
constexpr char SYM_RPL_VERSION[] = "RPL_VERSION";
using rpl_version = numeric_impl<NUM_RPL_VERSION, SYM_RPL_VERSION, 2>;

constexpr int NUM_RPL_WHOREPLY = 352;
constexpr char SYM_RPL_WHOREPLY[] = "RPL_WHOREPLY";
using rpl_whoreply = numeric_impl<NUM_RPL_WHOREPLY, SYM_RPL_WHOREPLY, 6>;

constexpr int NUM_RPL_ENDOFWHO = 315;
constexpr char SYM_RPL_ENDOFWHO[] = "RPL_ENDOFWHO";
using rpl_endofwho = numeric_impl<NUM_RPL_ENDOFWHO, SYM_RPL_ENDOFWHO, 1>;

constexpr int NUM_RPL_NAMREPLY = 353;
constexpr char SYM_RPL_NAMREPLY[] = "RPL_NAMREPLY";
using rpl_namreply = numeric_impl<NUM_RPL_NAMREPLY, SYM_RPL_NAMREPLY, 1>;

constexpr int NUM_RPL_ENDOFNAMES = 366;
constexpr char SYM_RPL_ENDOFNAMES[] = "RPL_ENDOFNAMES";
using rpl_endofnames = numeric_impl<NUM_RPL_ENDOFNAMES, SYM_RPL_ENDOFNAMES, 1>;

constexpr int NUM_RPL_LINKS = 364;
constexpr char SYM_RPL_LINKS[] = "RPL_LINKS";
using rpl_links = numeric_impl<NUM_RPL_LINKS, SYM_RPL_LINKS, 2>;

constexpr int NUM_RPL_ENDOFLINKS = 365;
constexpr char SYM_RPL_ENDOFLINKS[] = "RPL_ENDOFLINKS";
using rpl_endoflinks = numeric_impl<NUM_RPL_ENDOFLINKS, SYM_RPL_ENDOFLINKS, 1>;

constexpr int NUM_RPL_BANLIST = 367;
constexpr char SYM_RPL_BANLIST[] = "RPL_BANLIST";
using rpl_banlist = numeric_impl<NUM_RPL_BANLIST, SYM_RPL_BANLIST, 1>;

constexpr int NUM_RPL_ENDOFBANLIST = 368;
constexpr char SYM_RPL_ENDOFBANLIST[] = "RPL_ENDOFBANLIST";
using rpl_endofbanlist = numeric_impl<NUM_RPL_ENDOFBANLIST, SYM_RPL_ENDOFBANLIST, 1>;

constexpr int NUM_RPL_INFO = 371;
constexpr char SYM_RPL_INFO[] = "RPL_INFO";
using rpl_info = numeric_impl<NUM_RPL_INFO, SYM_RPL_INFO, 0>;

constexpr int NUM_RPL_ENDOFINFO = 374;
constexpr char SYM_RPL_ENDOFINFO[] = "RPL_ENDOFINFO";
using rpl_endofinfo = numeric_impl<NUM_RPL_ENDOFINFO, SYM_RPL_ENDOFINFO, 0>;

constexpr int NUM_RPL_MOTDSTART = 375;
constexpr char SYM_RPL_MOTDSTART[] = "RPL_MOTDSTART";
using rpl_motdstart = numeric_impl<NUM_RPL_MOTDSTART, SYM_RPL_MOTDSTART, 0>;

constexpr int NUM_RPL_MOTD = 372;
constexpr char SYM_RPL_MOTD[] = "RPL_MOTD";
using rpl_motd = numeric_impl<NUM_RPL_MOTD, SYM_RPL_MOTD, 0>;

constexpr int NUM_RPL_ENDOFMOTD = 376;
constexpr char SYM_RPL_ENDOFMOTD[] = "RPL_ENDOFMOTD";
using rpl_endofmotd = numeric_impl<NUM_RPL_ENDOFMOTD, SYM_RPL_ENDOFMOTD, 0>;

constexpr int NUM_RPL_YOUREOPER = 381;
constexpr char SYM_RPL_YOUREOPER[] = "RPL_YOUREOPER";
using rpl_youreoper = numeric_impl<NUM_RPL_YOUREOPER, SYM_RPL_YOUREOPER, 0>;

constexpr int NUM_RPL_REHASHING = 382;
constexpr char SYM_RPL_REHASHING[] = "RPL_REHASHING";
using rpl_rehashing = numeric_impl<NUM_RPL_REHASHING, SYM_RPL_REHASHING, 1>;

constexpr int NUM_RPL_TIME = 391;
constexpr char SYM_RPL_TIME[] = "RPL_TIME";
using rpl_time = numeric_impl<NUM_RPL_TIME, SYM_RPL_TIME, 1>;

constexpr int NUM_RPL_USERSSTART = 392;
constexpr char SYM_RPL_USERSSTART[] = "RPL_USERSSTART";
using rpl_usersstart = numeric_impl<NUM_RPL_USERSSTART, SYM_RPL_USERSSTART, 0>;

constexpr int NUM_RPL_USERS = 393;
constexpr char SYM_RPL_USERS[] = "RPL_USERS";
using rpl_users = numeric_impl<NUM_RPL_USERS, SYM_RPL_USERS, 0>;

constexpr int NUM_RPL_ENDOFUSERS = 394;
constexpr char SYM_RPL_ENDOFUSERS[] = "RPL_ENDOFUSERS";
using rpl_endofusers = numeric_impl<NUM_RPL_ENDOFUSERS, SYM_RPL_ENDOFUSERS, 0>;

constexpr int NUM_RPL_NOUSERS = 395;
constexpr char SYM_RPL_NOUSERS[] = "RPL_NOUSERS";
using rpl_nousers = numeric_impl<NUM_RPL_NOUSERS, SYM_RPL_NOUSERS, 0>;

constexpr int NUM_RPL_TRACELINK = 200;
constexpr char SYM_RPL_TRACELINK[] = "RPL_TRACELINK";
using rpl_tracelink = numeric_impl<NUM_RPL_TRACELINK, SYM_RPL_TRACELINK, 3>;

constexpr int NUM_RPL_TRACECONNECTING = 201;
constexpr char SYM_RPL_TRACECONNECTING[] = "RPL_TRACECONNECTING";
using rpl_traceconnecting = numeric_impl<NUM_RPL_TRACECONNECTING, SYM_RPL_TRACECONNECTING, 2>;

constexpr int NUM_RPL_TRACEHANDSHAKE = 202;
constexpr char SYM_RPL_TRACEHANDSHAKE[] = "RPL_TRACEHANDSHAKE";
using rpl_tracehandshake = numeric_impl<NUM_RPL_TRACEHANDSHAKE, SYM_RPL_TRACEHANDSHAKE, 2>;

constexpr int NUM_RPL_TRACEUNKNOWN = 203;
constexpr char SYM_RPL_TRACEUNKNOWN[] = "RPL_TRACEUNKNOWN";
using rpl_traceunknown = numeric_impl<NUM_RPL_TRACEUNKNOWN, SYM_RPL_TRACEUNKNOWN, 2>;

constexpr int NUM_RPL_TRACEOPERATOR = 204;
constexpr char SYM_RPL_TRACEOPERATOR[] = "RPL_TRACEOPERATOR";
using rpl_traceoperator = numeric_impl<NUM_RPL_TRACEOPERATOR, SYM_RPL_TRACEOPERATOR, 2>;

constexpr int NUM_RPL_TRACEUSER = 205;
constexpr char SYM_RPL_TRACEUSER[] = "RPL_TRACEUSER";
using rpl_traceuser = numeric_impl<NUM_RPL_TRACEUSER, SYM_RPL_TRACEUSER, 2>;

constexpr int NUM_RPL_TRACESERVER = 206;
constexpr char SYM_RPL_TRACESERVER[] = "RPL_TRACESERVER";
using rpl_traceserver = numeric_impl<NUM_RPL_TRACESERVER, SYM_RPL_TRACESERVER, 5>;

constexpr int NUM_RPL_TRACENEWTYPE = 208;
constexpr char SYM_RPL_TRACENEWTYPE[] = "RPL_TRACENEWTYPE";
using rpl_tracenewtype = numeric_impl<NUM_RPL_TRACENEWTYPE, SYM_RPL_TRACENEWTYPE, 2>;

constexpr int NUM_RPL_TRACELOG = 261;
constexpr char SYM_RPL_TRACELOG[] = "RPL_TRACELOG";
using rpl_tracelog = numeric_impl<NUM_RPL_TRACELOG, SYM_RPL_TRACELOG, 2>;

constexpr int NUM_RPL_STATSLINKINFO = 211;
constexpr char SYM_RPL_STATSLINKINFO[] = "RPL_STATSLINKINFO";
using rpl_statslinkinfo = numeric_impl<NUM_RPL_STATSLINKINFO, SYM_RPL_STATSLINKINFO, 6>;

constexpr int NUM_RPL_STATSCOMMANDS = 212;
constexpr char SYM_RPL_STATSCOMMANDS[] = "RPL_STATSCOMMANDS";
using rpl_statscommands = numeric_impl<NUM_RPL_STATSCOMMANDS, SYM_RPL_STATSCOMMANDS, 1>;

constexpr int NUM_RPL_STATSCLINE = 213;
constexpr char SYM_RPL_STATSCLINE[] = "RPL_STATSCLINE";
using rpl_statscline = numeric_impl<NUM_RPL_STATSCLINE, SYM_RPL_STATSCLINE, 5>;

constexpr int NUM_RPL_STATSNLINE = 214;
constexpr char SYM_RPL_STATSNLINE[] = "RPL_STATSNLINE";
using rpl_statsnline = numeric_impl<NUM_RPL_STATSNLINE, SYM_RPL_STATSNLINE, 5>;

constexpr int NUM_RPL_STATSILINE = 215;
constexpr char SYM_RPL_STATSILINE[] = "RPL_STATSILINE";
using rpl_statsiline = numeric_impl<NUM_RPL_STATSILINE, SYM_RPL_STATSILINE, 5>;

constexpr int NUM_RPL_STATSKLINE = 216;
constexpr char SYM_RPL_STATSKLINE[] = "RPL_STATSKLINE";
using rpl_statskline = numeric_impl<NUM_RPL_STATSKLINE, SYM_RPL_STATSKLINE, 5>;

constexpr int NUM_RPL_STATSYLINE = 218;
constexpr char SYM_RPL_STATSYLINE[] = "RPL_STATSYLINE";
using rpl_statsyline = numeric_impl<NUM_RPL_STATSYLINE, SYM_RPL_STATSYLINE, 4>;

constexpr int NUM_RPL_ENDOFSTATS = 219;
constexpr char SYM_RPL_ENDOFSTATS[] = "RPL_ENDOFSTATS";
using rpl_endofstats = numeric_impl<NUM_RPL_ENDOFSTATS, SYM_RPL_ENDOFSTATS, 1>;

constexpr int NUM_RPL_STATSLLINE = 241;
constexpr char SYM_RPL_STATSLLINE[] = "RPL_STATSLLINE";
using rpl_statslline = numeric_impl<NUM_RPL_STATSLLINE, SYM_RPL_STATSLLINE, 4>;

constexpr int NUM_RPL_STATSUPTIME = 242;
constexpr char SYM_RPL_STATSUPTIME[] = "RPL_STATSUPTIME";
using rpl_statsuptime = numeric_impl<NUM_RPL_STATSUPTIME, SYM_RPL_STATSUPTIME, 0>;

constexpr int NUM_RPL_STATSOLINE = 243;
constexpr char SYM_RPL_STATSOLINE[] = "RPL_STATSOLINE";
using rpl_statsoline = numeric_impl<NUM_RPL_STATSOLINE, SYM_RPL_STATSOLINE, 3>;

constexpr int NUM_RPL_STATSHLINE = 244;
constexpr char SYM_RPL_STATSHLINE[] = "RPL_STATSHLINE";
using rpl_statshline = numeric_impl<NUM_RPL_STATSHLINE, SYM_RPL_STATSHLINE, 3>;

constexpr int NUM_RPL_UMODEIS = 221;
constexpr char SYM_RPL_UMODEIS[] = "RPL_UMODEIS";
using rpl_umodeis = numeric_impl<NUM_RPL_UMODEIS, SYM_RPL_UMODEIS, 0>;

constexpr int NUM_RPL_LUSERCLIENT = 251;
constexpr char SYM_RPL_LUSERCLIENT[] = "RPL_LUSERCLIENT";
using rpl_luserclient = numeric_impl<NUM_RPL_LUSERCLIENT, SYM_RPL_LUSERCLIENT, 0>;

constexpr int NUM_RPL_LUSEROP = 252;
constexpr char SYM_RPL_LUSEROP[] = "RPL_LUSEROP";
using rpl_luserop = numeric_impl<NUM_RPL_LUSEROP, SYM_RPL_LUSEROP, 1>;

constexpr int NUM_RPL_LUSERUNKNOWN = 253;
constexpr char SYM_RPL_LUSERUNKNOWN[] = "RPL_LUSERUNKNOWN";
using rpl_luserunknown = numeric_impl<NUM_RPL_LUSERUNKNOWN, SYM_RPL_LUSERUNKNOWN, 1>;

constexpr int NUM_RPL_LUSERCHANNELS = 254;
constexpr char SYM_RPL_LUSERCHANNELS[] = "RPL_LUSERCHANNELS";
using rpl_luserchannels = numeric_impl<NUM_RPL_LUSERCHANNELS, SYM_RPL_LUSERCHANNELS, 1>;

constexpr int NUM_RPL_LUSERME = 255;
constexpr char SYM_RPL_LUSERME[] = "RPL_LUSERME";
using rpl_luserme = numeric_impl<NUM_RPL_LUSERME, SYM_RPL_LUSERME, 0>;

constexpr int NUM_RPL_ADMINME = 256;
constexpr char SYM_RPL_ADMINME[] = "RPL_ADMINME";
using rpl_adminme = numeric_impl<NUM_RPL_ADMINME, SYM_RPL_ADMINME, 1>;

constexpr int NUM_RPL_ADMINLOC1 = 257;
constexpr char SYM_RPL_ADMINLOC1[] = "RPL_ADMINLOC1";
using rpl_adminloc1 = numeric_impl<NUM_RPL_ADMINLOC1, SYM_RPL_ADMINLOC1, 0>;

constexpr int NUM_RPL_ADMINLOC2 = 258;
constexpr char SYM_RPL_ADMINLOC2[] = "RPL_ADMINLO2C";
using rpl_adminloc2 = numeric_impl<NUM_RPL_ADMINLOC2, SYM_RPL_ADMINLOC2, 0>;

constexpr int NUM_RPL_ADMINEMAIL = 259;
constexpr char SYM_RPL_ADMINEMAIL[] = "RPL_ADMINEMAIL";
using rpl_adminemail = numeric_impl<NUM_RPL_ADMINEMAIL, SYM_RPL_ADMINEMAIL, 0>;
}
}

#endif
