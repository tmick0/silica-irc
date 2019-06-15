#ifndef deserialize_h_
#define deserialize_h_

#include "protobase.h"

namespace silica {
namespace protocol {

std::shared_ptr<protobase> deserialize(const std::string& command);
}
}  // namespace silica

#endif