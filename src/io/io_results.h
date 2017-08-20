#ifndef io_results_h_
#define io_results_h_

#include <vector>
#include "io_base.h"

namespace silica {
namespace io {

enum io_result_type {
    RESULT_READ
};

struct io_result {

    io_result(io_base const& io, std::vector<uint8_t> const& result)
    : io(io)
    , result(result)
    , type(RESULT_READ)
    {}

    io_base const& io;
    std::vector<uint8_t> result;
    io_result_type type;
};

}
}

#endif
