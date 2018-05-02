#include "io_base.h"
#include "common/error.h"

#include <fcntl.h>
#include <unistd.h>

namespace silica {
namespace io {

io_base::~io_base() {
    if ((close(m_fd)) < 0) {
        print_error_errno("close(): ", errno);
    }
}

std::vector<uint8_t> io_base::read() const { return read(avail()); }

std::vector<uint8_t> io_base::read(size_t len) const {
    std::vector<uint8_t> res(len);
    res.resize(::read(m_fd, res.data(), len));
    return res;
}

void io_base::write(std::vector<uint8_t> const& data) const { ::write(m_fd, data.data(), data.size()); }

void io_base::write(std::string const& data) const {
    std::vector<uint8_t> v(data.begin(), data.end());
    write(v);
}
}
}
