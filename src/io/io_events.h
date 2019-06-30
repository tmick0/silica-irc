#ifndef io_events_h_
#define io_events_h_

#include <silica/io/io_base.h>

namespace silica {
namespace io {

enum io_event_type { EVENT_READABLE, EVENT_WRITEABLE, EVENT_EXCEPTION };

struct io_event {
    io_event(io_base const& io, io_event_type type) : io(io), type(type) {}

    io_base const& io;
    io_event_type type;
};
}  // namespace io
}  // namespace silica

#endif
