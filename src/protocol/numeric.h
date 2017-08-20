#ifndef numeric_h_
#define numeric_h_

#include <string>
#include <list>

namespace silica {
namespace protocol {

class numeric_base {
public:

};

template <int NumericCode, const char *SymbolicName, int NumArgs>
class numeric_impl : public numeric_base {
public:

    template <typename Container>
    numeric_impl(Container const& args)
    : m_args (args.begin(), args.end())
    {}

private:

    std::list<std::string> m_args;

};

/* error replies */

constexpr int  NUM_ERR_NOSUCHNICK   = 401;
constexpr char SYM_ERR_NOSUCHNICK[] = "ERR_NOSUCHNICK";
typedef numeric_impl<NUM_ERR_NOSUCHNICK, SYM_ERR_NOSUCHNICK, 1> err_nosuchnick;

constexpr int  NUM_ERR_NOSUCHSERVER   = 402;
constexpr char SYM_ERR_NOSUCHSERVER[] = "ERR_NOSUCHSERVER";
typedef numeric_impl<NUM_ERR_NOSUCHSERVER, SYM_ERR_NOSUCHSERVER, 1> err_nosuchserver;

constexpr int  NUM_ERR_NOSUCHCHANNEL   = 403;
constexpr char SYM_ERR_NOSUCHCHANNEL[] = "ERR_NOSUCHCHANNEL";
typedef numeric_impl<NUM_ERR_NOSUCHCHANNEL, SYM_ERR_NOSUCHCHANNEL, 1> err_nosuchchannel;

constexpr int  NUM_ERR_CANNOTSENDTOCHAN   = 404;
constexpr char SYM_ERR_CANNOTSENDTOCHAN[] = "ERR_CANNOTSENDTOCHAN";
typedef numeric_impl<NUM_ERR_CANNOTSENDTOCHAN, SYM_ERR_CANNOTSENDTOCHAN, 1> err_cannotsendtochan;

constexpr int  NUM_ERR_TOOMANYCHANNELS   = 405;
constexpr char SYM_ERR_TOOMANYCHANNELS[] = "ERR_TOOMANYCHANNELS";
typedef numeric_impl<NUM_ERR_TOOMANYCHANNELS, SYM_ERR_TOOMANYCHANNELS, 1> err_toomanychannels;

constexpr int  NUM_ERR_WASNOSUCHNICK   = 406;
constexpr char SYM_ERR_WASNOSUCHNICK[] = "ERR_WASNOSUCHNICK";
typedef numeric_impl<NUM_ERR_WASNOSUCHNICK, SYM_ERR_WASNOSUCHNICK, 1> err_wasnosuchnick;

constexpr int  NUM_ERR_TOOMANYTARGETS   = 407;
constexpr char SYM_ERR_TOOMANYTARGETS[] = "ERR_TOOMANYTARGETS";
typedef numeric_impl<NUM_ERR_TOOMANYTARGETS, SYM_ERR_TOOMANYTARGETS, 1> err_toomanytargets;

constexpr int  NUM_ERR_NOORIGIN   = 409;
constexpr char SYM_ERR_NOORIGIN[] = "ERR_NOORIGIN";
typedef numeric_impl<NUM_ERR_NOORIGIN, SYM_ERR_NOORIGIN, 0> err_noorigin;

constexpr int  NUM_ERR_NORECIPIENT   = 411;
constexpr char SYM_ERR_NORECIPIENT[] = "ERR_NORECIPIENT";
typedef numeric_impl<NUM_ERR_NORECIPIENT, SYM_ERR_NORECIPIENT, 0> err_norecipient;

constexpr int  NUM_ERR_NOTEXTTOSEND   = 412;
constexpr char SYM_ERR_NOTEXTTOSEND[] = "ERR_NOTEXTTOSEND";
typedef numeric_impl<NUM_ERR_NOTEXTTOSEND, SYM_ERR_NOTEXTTOSEND, 0> err_notexttosend;

constexpr int  NUM_ERR_NOTOPLEVEL   = 413;
constexpr char SYM_ERR_NOTOPLEVEL[] = "ERR_NOTOPLEVEL";
typedef numeric_impl<NUM_ERR_NOTOPLEVEL, SYM_ERR_NOTOPLEVEL, 1> err_notoplevel;

constexpr int  NUM_ERR_WILDTOPLEVEL   = 414;
constexpr char SYM_ERR_WILDTOPLEVEL[] = "ERR_WILDTOPLEVEL";
typedef numeric_impl<NUM_ERR_WILDTOPLEVEL, SYM_ERR_WILDTOPLEVEL, 1> err_wildtoplevel;

constexpr int  NUM_ERR_UNKNOWNCOMMAND   = 421;
constexpr char SYM_ERR_UNKNOWNCOMMAND[] = "ERR_UNKNOWNCOMMAND";
typedef numeric_impl<NUM_ERR_UNKNOWNCOMMAND, SYM_ERR_UNKNOWNCOMMAND, 1> err_unknowncommand;

constexpr int  NUM_ERR_NOMOTD   = 422;
constexpr char SYM_ERR_NOMOTD[] = "ERR_NOMOTD";
typedef numeric_impl<NUM_ERR_NOMOTD, SYM_ERR_NOMOTD, 0> err_nomotd;

constexpr int  NUM_ERR_NOADMININFO   = 423;
constexpr char SYM_ERR_NOADMININFO[] = "ERR_NOADMININFO";
typedef numeric_impl<NUM_ERR_NOADMININFO, SYM_ERR_NOADMININFO, 1> err_noadmininfo;

constexpr int  NUM_ERR_FILEERROR   = 424;
constexpr char SYM_ERR_FILEERROR[] = "ERR_FILEERROR";
typedef numeric_impl<NUM_ERR_FILEERROR, SYM_ERR_FILEERROR, 0> err_fileerror;

constexpr int  NUM_ERR_NONICKNAMEGIVEN   = 431;
constexpr char SYM_ERR_NONICKNAMEGIVEN[] = "ERR_NONICKNAMEGIVEN";
typedef numeric_impl<NUM_ERR_NONICKNAMEGIVEN, SYM_ERR_NONICKNAMEGIVEN, 0> err_nonicknamegiven;

constexpr int  NUM_ERR_ERRONEUSNICKNAME   = 432;
constexpr char SYM_ERR_ERRONEUSNICKNAME[] = "ERR_ERRONEUSNICKNAME";
typedef numeric_impl<NUM_ERR_ERRONEUSNICKNAME, SYM_ERR_ERRONEUSNICKNAME, 1> err_erroneusnickname;

constexpr int  NUM_ERR_NICKNAMEINUSE   = 433;
constexpr char SYM_ERR_NICKNAMEINUSE[] = "ERR_NICKNAMEINUSE";
typedef numeric_impl<NUM_ERR_NICKNAMEINUSE, SYM_ERR_NICKNAMEINUSE, 1> err_nicknameinuse;

constexpr int  NUM_ERR_NICKCOLLISION   = 436;
constexpr char SYM_ERR_NICKCOLLISION[] = "ERR_NICKCOLLISION";
typedef numeric_impl<NUM_ERR_NICKCOLLISION, SYM_ERR_NICKCOLLISION, 1> err_nickcollision;

constexpr int  NUM_ERR_USERNOTINCHANNEL   = 441;
constexpr char SYM_ERR_USERNOTINCHANNEL[] = "ERR_USERNOTINCHANNEL";
typedef numeric_impl<NUM_ERR_USERNOTINCHANNEL, SYM_ERR_USERNOTINCHANNEL, 2> err_usernotinchannel;

constexpr int  NUM_ERR_NOTONCHANNEL   = 442;
constexpr char SYM_ERR_NOTONCHANNEL[] = "ERR_NOTONCHANNEL";
typedef numeric_impl<NUM_ERR_NOTONCHANNEL, SYM_ERR_NOTONCHANNEL, 1> err_notonchannel;

constexpr int  NUM_ERR_USERONCHANNEL   = 443;
constexpr char SYM_ERR_USERONCHANNEL[] = "ERR_USERONCHANNEL";
typedef numeric_impl<NUM_ERR_USERONCHANNEL, SYM_ERR_USERONCHANNEL, 2> err_useronchannel;

constexpr int  NUM_ERR_NOLOGIN   = 444;
constexpr char SYM_ERR_NOLOGIN[] = "ERR_NOLOGIN";
typedef numeric_impl<NUM_ERR_NOLOGIN, SYM_ERR_NOLOGIN, 1> err_nologin;

constexpr int  NUM_ERR_SUMMONDISABLED   = 445;
constexpr char SYM_ERR_SUMMONDISABLED[] = "ERR_SUMMONDISABLED";
typedef numeric_impl<NUM_ERR_SUMMONDISABLED, SYM_ERR_SUMMONDISABLED, 0> err_summondisabled;

constexpr int  NUM_ERR_USERSDISABLED   = 446;
constexpr char SYM_ERR_USERSDISABLED[] = "ERR_USERSDISABLED";
typedef numeric_impl<NUM_ERR_USERSDISABLED, SYM_ERR_USERSDISABLED, 0> err_usersdisabled;

constexpr int  NUM_ERR_NOTREGISTERED   = 451;
constexpr char SYM_ERR_NOTREGISTERED[] = "ERR_NOTREGISTERED";
typedef numeric_impl<NUM_ERR_NOTREGISTERED, SYM_ERR_NOTREGISTERED, 0> err_notregistered;

constexpr int  NUM_ERR_NEEDMOREPARAMS   = 461;
constexpr char SYM_ERR_NEEDMOREPARAMS[] = "ERR_NEEDMOREPARAMS";
typedef numeric_impl<NUM_ERR_NEEDMOREPARAMS, SYM_ERR_NEEDMOREPARAMS, 1> err_needmoreparams;

constexpr int  NUM_ERR_ALREADYREGISTRED   = 462;
constexpr char SYM_ERR_ALREADYREGISTRED[] = "ERR_ALREADYREGISTRED";
typedef numeric_impl<NUM_ERR_ALREADYREGISTRED, SYM_ERR_ALREADYREGISTRED, 0> err_alreadyregistred;

constexpr int  NUM_ERR_NOPERMFORHOST   = 463;
constexpr char SYM_ERR_NOPERMFORHOST[] = "ERR_NOPERMFORHOST";
typedef numeric_impl<NUM_ERR_NOPERMFORHOST, SYM_ERR_NOPERMFORHOST, 0> err_nopermforhost;

constexpr int  NUM_ERR_PASSWDMISMATCH   = 464;
constexpr char SYM_ERR_PASSWDMISMATCH[] = "ERR_PASSWDMISMATCH";
typedef numeric_impl<NUM_ERR_PASSWDMISMATCH, SYM_ERR_PASSWDMISMATCH, 0> err_passwdmismatch;

constexpr int  NUM_ERR_YOUREBANNEDCREEP   = 465;
constexpr char SYM_ERR_YOUREBANNEDCREEP[] = "ERR_YOUREBANNEDCREEP";
typedef numeric_impl<NUM_ERR_YOUREBANNEDCREEP, SYM_ERR_YOUREBANNEDCREEP, 0> err_yourebannedcreep;

constexpr int  NUM_ERR_KEYSET   = 467;
constexpr char SYM_ERR_KEYSET[] = "ERR_KEYSET";
typedef numeric_impl<NUM_ERR_KEYSET, SYM_ERR_KEYSET, 1> err_keyset;

constexpr int  NUM_ERR_CHANNELISFULL   = 471;
constexpr char SYM_ERR_CHANNELISFULL[] = "ERR_CHANNELISFULL";
typedef numeric_impl<NUM_ERR_CHANNELISFULL, SYM_ERR_CHANNELISFULL, 1> err_channelisfull;

constexpr int  NUM_ERR_UNKNOWNMODE   = 472;
constexpr char SYM_ERR_UNKNOWNMODE[] = "ERR_UNKNOWNMODE";
typedef numeric_impl<NUM_ERR_UNKNOWNMODE, SYM_ERR_UNKNOWNMODE, 1> err_unknownmode;

constexpr int  NUM_ERR_INVITEONLYCHAN   = 473;
constexpr char SYM_ERR_INVITEONLYCHAN[] = "ERR_INVITEONLYCHAN";
typedef numeric_impl<NUM_ERR_INVITEONLYCHAN, SYM_ERR_INVITEONLYCHAN, 1> err_inviteonlychan;

constexpr int  NUM_ERR_BANNEDFROMCHAN   = 474;
constexpr char SYM_ERR_BANNEDFROMCHAN[] = "ERR_BANNEDFROMCHAN";
typedef numeric_impl<NUM_ERR_BANNEDFROMCHAN, SYM_ERR_BANNEDFROMCHAN, 1> err_bannedfromchan;

constexpr int  NUM_ERR_BADCHANNELKEY   = 475;
constexpr char SYM_ERR_BADCHANNELKEY[] = "ERR_BADCHANNELKEY";
typedef numeric_impl<NUM_ERR_BADCHANNELKEY, SYM_ERR_BADCHANNELKEY, 1> err_badchannelkey;

constexpr int  NUM_ERR_NOPRIVILEGES   = 481;
constexpr char SYM_ERR_NOPRIVILEGES[] = "ERR_NOPRIVILEGES";
typedef numeric_impl<NUM_ERR_NOPRIVILEGES, SYM_ERR_NOPRIVILEGES, 0> err_noprivileges;

constexpr int  NUM_ERR_CHANOPRIVSNEEDED   = 482;
constexpr char SYM_ERR_CHANOPRIVSNEEDED[] = "ERR_CHANOPRIVSNEEDED";
typedef numeric_impl<NUM_ERR_CHANOPRIVSNEEDED, SYM_ERR_CHANOPRIVSNEEDED, 1> err_chanoprivsneeded;

constexpr int  NUM_ERR_CANTKILLSERVER   = 483;
constexpr char SYM_ERR_CANTKILLSERVER[] = "ERR_CANTKILLSERVER";
typedef numeric_impl<NUM_ERR_CANTKILLSERVER, SYM_ERR_CANTKILLSERVER, 0> err_cantkillserver;

constexpr int  NUM_ERR_NOOPERHOST   = 491;
constexpr char SYM_ERR_NOOPERHOST[] = "ERR_NOOPERHOST";
typedef numeric_impl<NUM_ERR_NOOPERHOST, SYM_ERR_NOOPERHOST, 0> err_nooperhost;

constexpr int  NUM_ERR_UMODEUNKNOWNFLAG   = 501;
constexpr char SYM_ERR_UMODEUNKNOWNFLAG[] = "ERR_UMODEUNKNOWNFLAG";
typedef numeric_impl<NUM_ERR_UMODEUNKNOWNFLAG, SYM_ERR_UMODEUNKNOWNFLAG, 0> err_umodeunknownflag;

constexpr int  NUM_ERR_USERSDONTMATCH   = 502;
constexpr char SYM_ERR_USERSDONTMATCH[] = "ERR_USERSDONTMATCH";
typedef numeric_impl<NUM_ERR_USERSDONTMATCH, SYM_ERR_USERSDONTMATCH, 0> err_usersdontmatch;

/* replies */

constexpr int  NUM_RPL_USERHOST   = 302;
constexpr char SYM_RPL_USERHOST[] = "RPL_USERHOST";
typedef numeric_impl<NUM_RPL_USERHOST, SYM_RPL_USERHOST, 0> rpl_userhost;

constexpr int  NUM_RPL_ISON   = 303;
constexpr char SYM_RPL_ISON[] = "RPL_ISON";
typedef numeric_impl<NUM_RPL_ISON, SYM_RPL_ISON, 0> rpl_ison;

constexpr int  NUM_RPL_AWAY   = 301;
constexpr char SYM_RPL_AWAY[] = "RPL_AWAY";
typedef numeric_impl<NUM_RPL_AWAY, SYM_RPL_AWAY, 1> rpl_away;

constexpr int  NUM_RPL_UNAWAY   = 305;
constexpr char SYM_RPL_UNAWAY[] = "RPL_UNAWAY";
typedef numeric_impl<NUM_RPL_UNAWAY, SYM_RPL_UNAWAY, 0> rpl_unaway;

constexpr int  NUM_RPL_NOWAWAY   = 306;
constexpr char SYM_RPL_NOWAWAY[] = "RPL_NOWAWAY";
typedef numeric_impl<NUM_RPL_NOWAWAY, SYM_RPL_NOWAWAY, 0> rpl_nowaway;

constexpr int  NUM_RPL_WHOISUSER   = 311;
constexpr char SYM_RPL_WHOISUSER[] = "RPL_WHOISUSER";
typedef numeric_impl<NUM_RPL_WHOISUSER, SYM_RPL_WHOISUSER, 4> rpl_whoisuser;

constexpr int  NUM_RPL_WHOISSERVER   = 312;
constexpr char SYM_RPL_WHOISSERVER[] = "RPL_WHOISSERVER";
typedef numeric_impl<NUM_RPL_WHOISSERVER, SYM_RPL_WHOISSERVER, 2> rpl_whoisserver;

constexpr int  NUM_RPL_WHOISOPERATOR   = 313;
constexpr char SYM_RPL_WHOISOPERATOR[] = "RPL_WHOISOPERATOR";
typedef numeric_impl<NUM_RPL_WHOISOPERATOR, SYM_RPL_WHOISOPERATOR, 1> rpl_whoisoperator;

constexpr int  NUM_RPL_WHOISIDLE   = 317;
constexpr char SYM_RPL_WHOISIDLE[] = "RPL_WHOISIDLE";
typedef numeric_impl<NUM_RPL_WHOISIDLE, SYM_RPL_WHOISIDLE, 2> rpl_whoisidle;

constexpr int  NUM_RPL_ENDOFWHOIS   = 318;
constexpr char SYM_RPL_ENDOFWHOIS[] = "RPL_ENDOFWHOIS";
typedef numeric_impl<NUM_RPL_ENDOFWHOIS, SYM_RPL_ENDOFWHOIS, 1> rpl_endofwhois;

constexpr int  NUM_RPL_WHOISCHANNELS   = 319;
constexpr char SYM_RPL_WHOISCHANNELS[] = "RPL_WHOISCHANNELS";
typedef numeric_impl<NUM_RPL_WHOISCHANNELS, SYM_RPL_WHOISCHANNELS, 1> rpl_whoischannels;

constexpr int  NUM_RPL_WHOWASUSER   = 314;
constexpr char SYM_RPL_WHOWASUSER[] = "RPL_WHOWASUSER";
typedef numeric_impl<NUM_RPL_WHOWASUSER, SYM_RPL_WHOWASUSER, 4> rpl_whowasuser;

constexpr int  NUM_RPL_ENDOFWHOWAS   = 369;
constexpr char SYM_RPL_ENDOFWHOWAS[] = "RPL_ENDOFWHOWAS";
typedef numeric_impl<NUM_RPL_ENDOFWHOWAS, SYM_RPL_ENDOFWHOWAS, 1> rpl_endofwhowas;

constexpr int  NUM_RPL_LISTSTART   = 321;
constexpr char SYM_RPL_LISTSTART[] = "RPL_LISTSTART";
typedef numeric_impl<NUM_RPL_LISTSTART, SYM_RPL_LISTSTART, 1> rpl_liststart;

constexpr int  NUM_RPL_LIST   = 322;
constexpr char SYM_RPL_LIST[] = "RPL_LIST";
typedef numeric_impl<NUM_RPL_LIST, SYM_RPL_LIST, 2> rpl_list;

constexpr int  NUM_RPL_LISTEND   = 323;
constexpr char SYM_RPL_LISTEND[] = "RPL_LISTEND";
typedef numeric_impl<NUM_RPL_LISTEND, SYM_RPL_LISTEND, 1> rpl_listend;

constexpr int  NUM_RPL_CHANNELMODEIS   = 324;
constexpr char SYM_RPL_CHANNELMODEIS[] = "RPL_CHANNELMODEIS";
typedef numeric_impl<NUM_RPL_CHANNELMODEIS, SYM_RPL_CHANNELMODEIS, 3> rpl_channelmodeis;

constexpr int  NUM_RPL_NOTOPIC   = 331;
constexpr char SYM_RPL_NOTOPIC[] = "RPL_NOTOPIC";
typedef numeric_impl<NUM_RPL_NOTOPIC, SYM_RPL_NOTOPIC, 1> rpl_notopic;

constexpr int  NUM_RPL_TOPIC   = 332;
constexpr char SYM_RPL_TOPIC[] = "RPL_TOPIC";
typedef numeric_impl<NUM_RPL_TOPIC, SYM_RPL_TOPIC, 1> rpl_topic;

constexpr int  NUM_RPL_INVITING   = 341;
constexpr char SYM_RPL_INVITING[] = "RPL_INVITING";
typedef numeric_impl<NUM_RPL_INVITING, SYM_RPL_INVITING, 1> rpl_inviting;

constexpr int  NUM_RPL_SUMMONING   = 342;
constexpr char SYM_RPL_SUMMONING[] = "RPL_SUMMONING";
typedef numeric_impl<NUM_RPL_SUMMONING, SYM_RPL_SUMMONING, 1> rpl_summoning;

constexpr int  NUM_RPL_VERSION   = 351;
constexpr char SYM_RPL_VERSION[] = "RPL_VERSION";
typedef numeric_impl<NUM_RPL_VERSION, SYM_RPL_VERSION, 2> rpl_version;

constexpr int  NUM_RPL_WHOREPLY   = 352;
constexpr char SYM_RPL_WHOREPLY[] = "RPL_WHOREPLY";
typedef numeric_impl<NUM_RPL_WHOREPLY, SYM_RPL_WHOREPLY, 6> rpl_whoreply;

constexpr int  NUM_RPL_ENDOFWHO   = 315;
constexpr char SYM_RPL_ENDOFWHO[] = "RPL_ENDOFWHO";
typedef numeric_impl<NUM_RPL_ENDOFWHO, SYM_RPL_ENDOFWHO, 1> rpl_endofwho;

constexpr int  NUM_RPL_NAMREPLY   = 353;
constexpr char SYM_RPL_NAMREPLY[] = "RPL_NAMREPLY";
typedef numeric_impl<NUM_RPL_NAMREPLY, SYM_RPL_NAMREPLY, 1> rpl_namreply;

constexpr int  NUM_RPL_ENDOFNAMES   = 366;
constexpr char SYM_RPL_ENDOFNAMES[] = "RPL_ENDOFNAMES";
typedef numeric_impl<NUM_RPL_ENDOFNAMES, SYM_RPL_ENDOFNAMES, 1> rpl_endofnames;

constexpr int  NUM_RPL_LINKS   = 364;
constexpr char SYM_RPL_LINKS[] = "RPL_LINKS";
typedef numeric_impl<NUM_RPL_LINKS, SYM_RPL_LINKS, 2> rpl_links;

constexpr int  NUM_RPL_ENDOFLINKS   = 365;
constexpr char SYM_RPL_ENDOFLINKS[] = "RPL_ENDOFLINKS";
typedef numeric_impl<NUM_RPL_ENDOFLINKS, SYM_RPL_ENDOFLINKS, 1> rpl_endoflinks;

constexpr int  NUM_RPL_BANLIST   = 367;
constexpr char SYM_RPL_BANLIST[] = "RPL_BANLIST";
typedef numeric_impl<NUM_RPL_BANLIST, SYM_RPL_BANLIST, 1> rpl_banlist;

constexpr int  NUM_RPL_ENDOFBANLIST   = 368;
constexpr char SYM_RPL_ENDOFBANLIST[] = "RPL_ENDOFBANLIST";
typedef numeric_impl<NUM_RPL_ENDOFBANLIST, SYM_RPL_ENDOFBANLIST, 1> rpl_endofbanlist;

constexpr int  NUM_RPL_INFO   = 371;
constexpr char SYM_RPL_INFO[] = "RPL_INFO";
typedef numeric_impl<NUM_RPL_INFO, SYM_RPL_INFO, 0> rpl_info;

constexpr int  NUM_RPL_ENDOFINFO   = 374;
constexpr char SYM_RPL_ENDOFINFO[] = "RPL_ENDOFINFO";
typedef numeric_impl<NUM_RPL_ENDOFINFO, SYM_RPL_ENDOFINFO, 0> rpl_endofinfo;

constexpr int  NUM_RPL_MOTDSTART   = 375;
constexpr char SYM_RPL_MOTDSTART[] = "RPL_MOTDSTART";
typedef numeric_impl<NUM_RPL_MOTDSTART, SYM_RPL_MOTDSTART, 0> rpl_motdstart;

constexpr int  NUM_RPL_MOTD   = 372;
constexpr char SYM_RPL_MOTD[] = "RPL_MOTD";
typedef numeric_impl<NUM_RPL_MOTD, SYM_RPL_MOTD, 0> rpl_motd;

constexpr int  NUM_RPL_ENDOFMOTD   = 376;
constexpr char SYM_RPL_ENDOFMOTD[] = "RPL_ENDOFMOTD";
typedef numeric_impl<NUM_RPL_ENDOFMOTD, SYM_RPL_ENDOFMOTD, 0> rpl_endofmotd;

constexpr int  NUM_RPL_YOUREOPER   = 381;
constexpr char SYM_RPL_YOUREOPER[] = "RPL_YOUREOPER";
typedef numeric_impl<NUM_RPL_YOUREOPER, SYM_RPL_YOUREOPER, 0> rpl_youreoper;

constexpr int  NUM_RPL_REHASHING   = 382;
constexpr char SYM_RPL_REHASHING[] = "RPL_REHASHING";
typedef numeric_impl<NUM_RPL_REHASHING, SYM_RPL_REHASHING, 1> rpl_rehashing;

constexpr int  NUM_RPL_TIME   = 391;
constexpr char SYM_RPL_TIME[] = "RPL_TIME";
typedef numeric_impl<NUM_RPL_TIME, SYM_RPL_TIME, 1> rpl_time;

constexpr int  NUM_RPL_USERSSTART   = 392;
constexpr char SYM_RPL_USERSSTART[] = "RPL_USERSSTART";
typedef numeric_impl<NUM_RPL_USERSSTART, SYM_RPL_USERSSTART, 0> rpl_usersstart;

constexpr int  NUM_RPL_USERS   = 393;
constexpr char SYM_RPL_USERS[] = "RPL_USERS";
typedef numeric_impl<NUM_RPL_USERS, SYM_RPL_USERS, 0> rpl_users;

constexpr int  NUM_RPL_ENDOFUSERS   = 394;
constexpr char SYM_RPL_ENDOFUSERS[] = "RPL_ENDOFUSERS";
typedef numeric_impl<NUM_RPL_ENDOFUSERS, SYM_RPL_ENDOFUSERS, 0> rpl_endofusers;

constexpr int  NUM_RPL_NOUSERS   = 395;
constexpr char SYM_RPL_NOUSERS[] = "RPL_NOUSERS";
typedef numeric_impl<NUM_RPL_NOUSERS, SYM_RPL_NOUSERS, 0> rpl_nousers;

constexpr int  NUM_RPL_TRACELINK   = 200;
constexpr char SYM_RPL_TRACELINK[] = "RPL_TRACELINK";
typedef numeric_impl<NUM_RPL_TRACELINK, SYM_RPL_TRACELINK, 3> rpl_tracelink;

constexpr int  NUM_RPL_TRACECONNECTING   = 201;
constexpr char SYM_RPL_TRACECONNECTING[] = "RPL_TRACECONNECTING";
typedef numeric_impl<NUM_RPL_TRACECONNECTING, SYM_RPL_TRACECONNECTING, 2> rpl_traceconnecting;

constexpr int  NUM_RPL_TRACEHANDSHAKE   = 202;
constexpr char SYM_RPL_TRACEHANDSHAKE[] = "RPL_TRACEHANDSHAKE";
typedef numeric_impl<NUM_RPL_TRACEHANDSHAKE, SYM_RPL_TRACEHANDSHAKE, 2> rpl_tracehandshake;

constexpr int  NUM_RPL_TRACEUNKNOWN   = 203;
constexpr char SYM_RPL_TRACEUNKNOWN[] = "RPL_TRACEUNKNOWN";
typedef numeric_impl<NUM_RPL_TRACEUNKNOWN, SYM_RPL_TRACEUNKNOWN, 2> rpl_traceunknown;

constexpr int  NUM_RPL_TRACEOPERATOR   = 204;
constexpr char SYM_RPL_TRACEOPERATOR[] = "RPL_TRACEOPERATOR";
typedef numeric_impl<NUM_RPL_TRACEOPERATOR, SYM_RPL_TRACEOPERATOR, 2> rpl_traceoperator;

constexpr int  NUM_RPL_TRACEUSER   = 205;
constexpr char SYM_RPL_TRACEUSER[] = "RPL_TRACEUSER";
typedef numeric_impl<NUM_RPL_TRACEUSER, SYM_RPL_TRACEUSER, 2> rpl_traceuser;

constexpr int  NUM_RPL_TRACESERVER   = 206;
constexpr char SYM_RPL_TRACESERVER[] = "RPL_TRACESERVER";
typedef numeric_impl<NUM_RPL_TRACESERVER, SYM_RPL_TRACESERVER, 5> rpl_traceserver;

constexpr int  NUM_RPL_TRACENEWTYPE   = 208;
constexpr char SYM_RPL_TRACENEWTYPE[] = "RPL_TRACENEWTYPE";
typedef numeric_impl<NUM_RPL_TRACENEWTYPE, SYM_RPL_TRACENEWTYPE, 2> rpl_tracenewtype;

constexpr int  NUM_RPL_TRACELOG   = 261;
constexpr char SYM_RPL_TRACELOG[] = "RPL_TRACELOG";
typedef numeric_impl<NUM_RPL_TRACELOG, SYM_RPL_TRACELOG, 2> rpl_tracelog;

constexpr int  NUM_RPL_STATSLINKINFO   = 211;
constexpr char SYM_RPL_STATSLINKINFO[] = "RPL_STATSLINKINFO";
typedef numeric_impl<NUM_RPL_STATSLINKINFO, SYM_RPL_STATSLINKINFO, 6> rpl_statslinkinfo;

constexpr int  NUM_RPL_STATSCOMMANDS   = 212;
constexpr char SYM_RPL_STATSCOMMANDS[] = "RPL_STATSCOMMANDS";
typedef numeric_impl<NUM_RPL_STATSCOMMANDS, SYM_RPL_STATSCOMMANDS, 1> rpl_statscommands;

constexpr int  NUM_RPL_STATSCLINE   = 213;
constexpr char SYM_RPL_STATSCLINE[] = "RPL_STATSCLINE";
typedef numeric_impl<NUM_RPL_STATSCLINE, SYM_RPL_STATSCLINE, 5> rpl_statscline;

constexpr int  NUM_RPL_STATSNLINE   = 214;
constexpr char SYM_RPL_STATSNLINE[] = "RPL_STATSNLINE";
typedef numeric_impl<NUM_RPL_STATSNLINE, SYM_RPL_STATSNLINE, 5> rpl_statsnline;

constexpr int  NUM_RPL_STATSILINE   = 215;
constexpr char SYM_RPL_STATSILINE[] = "RPL_STATSILINE";
typedef numeric_impl<NUM_RPL_STATSILINE, SYM_RPL_STATSILINE, 5> rpl_statsiline;

constexpr int  NUM_RPL_STATSKLINE   = 216;
constexpr char SYM_RPL_STATSKLINE[] = "RPL_STATSKLINE";
typedef numeric_impl<NUM_RPL_STATSKLINE, SYM_RPL_STATSKLINE, 5> rpl_statskline;

constexpr int  NUM_RPL_STATSYLINE   = 218;
constexpr char SYM_RPL_STATSYLINE[] = "RPL_STATSYLINE";
typedef numeric_impl<NUM_RPL_STATSYLINE, SYM_RPL_STATSYLINE, 4> rpl_statsyline;

constexpr int  NUM_RPL_ENDOFSTATS   = 219;
constexpr char SYM_RPL_ENDOFSTATS[] = "RPL_ENDOFSTATS";
typedef numeric_impl<NUM_RPL_ENDOFSTATS, SYM_RPL_ENDOFSTATS, 1> rpl_endofstats;

constexpr int  NUM_RPL_STATSLLINE   = 241;
constexpr char SYM_RPL_STATSLLINE[] = "RPL_STATSLLINE";
typedef numeric_impl<NUM_RPL_STATSLLINE, SYM_RPL_STATSLLINE, 4> rpl_statslline;

constexpr int  NUM_RPL_STATSUPTIME   = 242;
constexpr char SYM_RPL_STATSUPTIME[] = "RPL_STATSUPTIME";
typedef numeric_impl<NUM_RPL_STATSUPTIME, SYM_RPL_STATSUPTIME, 0> rpl_statsuptime;

constexpr int  NUM_RPL_STATSOLINE   = 243;
constexpr char SYM_RPL_STATSOLINE[] = "RPL_STATSOLINE";
typedef numeric_impl<NUM_RPL_STATSOLINE, SYM_RPL_STATSOLINE, 3> rpl_statsoline;

constexpr int  NUM_RPL_STATSHLINE   = 244;
constexpr char SYM_RPL_STATSHLINE[] = "RPL_STATSHLINE";
typedef numeric_impl<NUM_RPL_STATSHLINE, SYM_RPL_STATSHLINE, 3> rpl_statshline;

constexpr int  NUM_RPL_UMODEIS   = 221;
constexpr char SYM_RPL_UMODEIS[] = "RPL_UMODEIS";
typedef numeric_impl<NUM_RPL_UMODEIS, SYM_RPL_UMODEIS, 0> rpl_umodeis;

constexpr int  NUM_RPL_LUSERCLIENT   = 251;
constexpr char SYM_RPL_LUSERCLIENT[] = "RPL_LUSERCLIENT";
typedef numeric_impl<NUM_RPL_LUSERCLIENT, SYM_RPL_LUSERCLIENT, 0> rpl_luserclient;

constexpr int  NUM_RPL_LUSEROP   = 252;
constexpr char SYM_RPL_LUSEROP[] = "RPL_LUSEROP";
typedef numeric_impl<NUM_RPL_LUSEROP, SYM_RPL_LUSEROP, 1> rpl_luserop;

constexpr int  NUM_RPL_LUSERUNKNOWN   = 253;
constexpr char SYM_RPL_LUSERUNKNOWN[] = "RPL_LUSERUNKNOWN";
typedef numeric_impl<NUM_RPL_LUSERUNKNOWN, SYM_RPL_LUSERUNKNOWN, 1> rpl_luserunknown;

constexpr int  NUM_RPL_LUSERCHANNELS   = 254;
constexpr char SYM_RPL_LUSERCHANNELS[] = "RPL_LUSERCHANNELS";
typedef numeric_impl<NUM_RPL_LUSERCHANNELS, SYM_RPL_LUSERCHANNELS, 1> rpl_luserchannels;

constexpr int  NUM_RPL_LUSERME   = 255;
constexpr char SYM_RPL_LUSERME[] = "RPL_LUSERME";
typedef numeric_impl<NUM_RPL_LUSERME, SYM_RPL_LUSERME, 0> rpl_luserme;

constexpr int  NUM_RPL_ADMINME   = 256;
constexpr char SYM_RPL_ADMINME[] = "RPL_ADMINME";
typedef numeric_impl<NUM_RPL_ADMINME, SYM_RPL_ADMINME, 1> rpl_adminme;

constexpr int  NUM_RPL_ADMINLOC1   = 257;
constexpr char SYM_RPL_ADMINLOC1[] = "RPL_ADMINLOC1";
typedef numeric_impl<NUM_RPL_ADMINLOC1, SYM_RPL_ADMINLOC1, 0> rpl_adminloc1;

constexpr int  NUM_RPL_ADMINLOC2   = 258;
constexpr char SYM_RPL_ADMINLOC2[] = "RPL_ADMINLO2C";
typedef numeric_impl<NUM_RPL_ADMINLOC2, SYM_RPL_ADMINLOC2, 0> rpl_adminloc2;

constexpr int  NUM_RPL_ADMINEMAIL   = 259;
constexpr char SYM_RPL_ADMINEMAIL[] = "RPL_ADMINEMAIL";
typedef numeric_impl<NUM_RPL_ADMINEMAIL, SYM_RPL_ADMINEMAIL, 0> rpl_adminemail;

}
}

#endif
