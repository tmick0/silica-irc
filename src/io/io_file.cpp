#include "io_file.h"
#include "common/error.h"

#include <fcntl.h>
#include <unistd.h>

namespace silica {
namespace io {

const std::unordered_map<std::string, int> io_file::flag_map = {
    { "r",  O_RDONLY                      },
    { "r+", O_RDWR                        },
    { "w",  O_WRONLY | O_CREAT | O_TRUNC  },
    { "w+", O_RDWR   | O_CREAT | O_TRUNC  },
    { "a",  O_WRONLY | O_CREAT | O_APPEND },
    { "a+", O_RDWR   | O_CREAT | O_APPEND }
};

int io_file::decode_flags(const std::string& flags) {
    const std::unordered_map<std::string, int>::const_iterator it (flag_map.find(flags));
    if(it == flag_map.end()){
        make_error("socket_wrapper_file: invalid file flags '" << flags << "'");
    }
    return it->second;
}

io_file::io_file(std::string const& filename, std::string const& flags) {
    if((m_fd = open(filename.c_str(), decode_flags(flags))) < 0) {
        make_error("open()");
    }
}

bool io_file::valid() {
    return true;
}

size_t io_file::avail() const {
    ssize_t orig;
    ssize_t result;
    if((orig = lseek(m_fd, 0, SEEK_CUR)) == -1){
        make_error("lseek(): errno = " << errno);
    }
    if((result = lseek(m_fd, 0, SEEK_END)) == -1){
        make_error("lseek(): errno = " << errno);
    }
    if(lseek(m_fd, orig, SEEK_SET) == -1){
        make_error("lseek(): errno = " << errno);
    }
    return result - orig;
}


}
}
