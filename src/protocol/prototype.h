#ifndef prototype_h_
#define prototype_h_

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
    bool operator==(const prototype& other) const;
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

    template <int NumericCode, const char* SymbolicName, int NumArgs>
    friend class numeric_impl;
};

}  // namespace protocol
}  // namespace silica

#endif