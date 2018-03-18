#ifndef io_base_h_
#define io_base_h_

#include <cstdint>
#include <cstring>
#include <string>
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

    virtual std::vector<uint8_t> read(size_t len) const;
    virtual void write(std::vector<uint8_t> const& data) const;

    std::vector<uint8_t> read() const;
    void write(std::string const& data) const;

    friend class io_manager;

protected:
    virtual size_t avail() const = 0;

    io_base() = default;
    int m_fd;
};
}
}

#endif
