#ifndef time_h_
#define time_h_

#include <sys/time.h>
#include <chrono>

namespace silica {

template <typename T>
inline timeval duration_to_timeval(T const& d) {
    const std::chrono::microseconds u = std::chrono::duration_cast<std::chrono::microseconds>(d);
    const int64_t micro_per_sec = 1e6;
    return timeval{u.count() / micro_per_sec, u.count() % micro_per_sec};
}

}

#endif
