#include "prototype.h"

#include <string>

namespace silica {
namespace protocol {

bool prototype::operator==(const prototype& other) const {
    return std::string{m_commandString} ==
           std::string{
               other.m_commandString};  // should be sufficient unless someones goes playing games with the types
}

const char* prototype::commandSymbol() const { return m_commandSymbol; }

const char* prototype::commandString() const { return m_commandString; }

bool prototype::lastArgVarLen() const { return m_lastArgVarLen; }

int prototype::numOptional() const { return m_numOptional; }

int prototype::numRequired() const { return m_numRequired; }

}
}