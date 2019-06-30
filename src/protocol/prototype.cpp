#include <silica/protocol/prototype.h>

#include <string>

namespace silica {
namespace protocol {

const char* prototype::commandSymbol() const { return m_commandSymbol; }

const char* prototype::commandString() const { return m_commandString; }

bool prototype::lastArgVarLen() const { return m_lastArgVarLen; }

int prototype::numOptional() const { return m_numOptional; }

int prototype::numRequired() const { return m_numRequired; }

}  // namespace protocol
}  // namespace silica