#ifndef protobase_h_
#define protobase_h_

#include <memory>

#include "prototype.h"

#include "common/error.h"

namespace silica {
namespace protocol {

// forward decls
class numeric_base;
class command_base;

class protobase {
public:
    virtual prototype getPrototype() const = 0;
    virtual bool isNumeric() const = 0;
    virtual std::shared_ptr<numeric_base> numeric() { make_error("not a numeric message"); };
    virtual std::shared_ptr<command_base> command() { make_error("not a command message"); };
};

}  // namespace protocol
}  // namespace silica

#endif