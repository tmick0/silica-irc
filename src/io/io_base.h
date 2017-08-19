#ifndef io_base_h_
#define io_base_h_

#include <cstdint>
#include <cstring>
#include <vector>

namespace silica {
namespace io {

// forward decl
class io_manager;

class io_base {
public:

    io_base(io_base const& o) = delete;
    io_base(io_base&& o) = delete;

    virtual ~io_base();
    virtual bool valid() = 0;

    std::vector<uint8_t> read(size_t len);

    friend class io_manager;

protected:

    io_base() = default;
    int m_fd;

};

}
}

#endif
