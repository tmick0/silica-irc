#include "numeric.h"

namespace silica {
namespace protocol {

bool numeric_base::operator==(const numeric_base& other) const {
    return getPrototype() == other.getPrototype() && m_args == other.m_args;
}

}  // namespace protocol
}  // namespace silica