#include "commands.h"

#include "common/error.h"

namespace silica {
namespace protocol {

bool command_base::operator==(const command_base& other) const {
    return getPrototype() == other.getPrototype() && m_args == other.m_args;
}

}  // namespace protocol
}  // namespace silica
