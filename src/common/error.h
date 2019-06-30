#ifndef error_h_
#define error_h_

#include <cstring>
#include <exception>
#include <sstream>

#include <iostream>

#define construct_error(e, data)                            \
    do {                                                    \
        e << "[" << __FILE__ + strlen(__SOURCE_ROOT__) + 1; \
        e << ":" << __LINE__ << "] ";                       \
        e << data << silica::error::flush;                  \
    } while (0);

#define construct_error_errno(e, data, errno)                             \
    do {                                                                  \
        char _strerror_buf[64];                                           \
        construct_error(e, data << strerror_r(errno, _strerror_buf, 64)); \
    } while (0);

#define make_error(data)          \
    do {                          \
        silica::error e;          \
        construct_error(e, data); \
        throw e;                  \
    } while (0);

#define make_error_errno(data, errno)          \
    do {                                       \
        silica::error e;                       \
        construct_error_errno(e, data, errno); \
        throw e;                               \
    } while (0);

#define print_error(data)         \
    do {                          \
        silica::error e;          \
        construct_error(e, data); \
        std::cerr << e;           \
    } while (0);

#define print_error_errno(data, errno)         \
    do {                                       \
        silica::error e;                       \
        construct_error_errno(e, data, errno); \
        std::cerr << e;                        \
    } while (0);

namespace silica {

class error : public std::exception {
public:
    error() = default;

    error(std::string const& what) : m_stream(what), m_string(what) {}

    const char* what() const noexcept override { return m_string.c_str(); }

    struct _flush_t {
    private:
        _flush_t() = default;
    };

    static const _flush_t flush;

    template <typename T>
    friend error& operator<<(error& e, T const& s);

    friend error& operator<<(error& e, _flush_t const& s);

private:
    std::stringstream m_stream;
    std::string m_string;
};

inline std::ostream& operator<<(std::ostream& os, const error& e) {
    os << e.what() << std::endl;
    return os;
}

template <typename T>
inline error& operator<<(error& e, T const& s) {
    e.m_stream << s;
    return e;
}

inline error& operator<<(error& e, error::_flush_t const& f) {
    e.m_string = e.m_stream.str();
    return e;
}
}  // namespace silica

#endif
