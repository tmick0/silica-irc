#ifndef prototype_h_
#define prototype_h_

#include <string>

namespace silica {
namespace protocol {

class prototype {
public:
    virtual ~prototype(){};

    const char* commandSymbol() const;
    const char* commandString() const;
    bool isNumeric() const;
    int numRequired() const;
    int numOptional() const;
    bool lastArgVarLen() const;
    virtual bool is_numeric() { return false; };

protected:
    constexpr prototype(const char* commandString, const char* commandSymbol, int numRequired, int numOptional,
                        bool lastArgVarLen)
        : m_commandString(commandString),
          m_commandSymbol(commandSymbol),
          m_numRequired(numRequired),
          m_numOptional(numOptional),
          m_lastArgVarLen(lastArgVarLen) {}

    const char* m_commandString;
    const char* m_commandSymbol;
    int m_numRequired;
    int m_numOptional;
    bool m_lastArgVarLen;

    template <const char* CommandString, int NumRequired, int NumOptional, bool LastArgVarLen>
    friend class command_impl;

    template <const char* NumericCode, const char* SymbolicName, int NumArgs>
    friend class numeric_impl;
};

inline bool operator==(const prototype& a, const prototype& b) {
    return std::string{a.commandString()} == std::string{b.commandString()};
}

inline bool operator!=(const prototype& a, const prototype& b) { return !(a == b); }

}  // namespace protocol
}  // namespace silica

#endif