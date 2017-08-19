#include "io_base.h"
#include "common/error.h"

#include <fcntl.h>
#include <unistd.h>

namespace silica {
namespace io {

io_base::~io_base() {
    if((close(m_fd)) < 0) {
        make_error("close()");
    }
}

std::vector<uint8_t> io_base::read(size_t len) {
    std::vector<uint8_t> res (len);
    ::read(m_fd, res.data(), len);
    return res;
}

}
}
