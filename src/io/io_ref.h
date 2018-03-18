#ifndef io_ref_h_
#define io_ref_h_

#include "io_base.h"

namespace silica {
namespace io {

struct io_ref {

    io_base const& io;

    io_ref(io_base const& io)
    : io(io)
    {}

    bool operator <(io_ref const& other) const {
        return &io < &other.io;
    }

};

}
}

#endif
