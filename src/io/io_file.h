#ifndef io_file_h_
#define io_file_h_

#include "io_base.h"

#include <string>
#include <unordered_map>

namespace silica {
namespace io {

class io_file : public io_base {
public:

    io_file(std::string const& filename, std::string const& flags="r");
    virtual bool valid() override;

protected:

    virtual size_t avail() const override;

private:

    static int decode_flags(std::string const& flags);
    static const std::unordered_map<std::string, int> flag_map;

};

}
}

#endif
