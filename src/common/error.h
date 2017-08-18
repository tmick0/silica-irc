#ifndef error_h_
#define error_h_

#include <exception>
#include <sstream>

#include <iostream>

#define make_error(data) do { silica::error e; e << data << silica::error::flush; throw e; } while(0);

namespace silica {

class error : public std::exception {
public:

    error() = default;

    error(std::string const& what)
    : m_stream(what)
    , m_string(what)
    {}

    const char* what() const noexcept override {
        return m_string.c_str();
    }

    struct _flush_t {
    private:
        _flush_t() = default;
    };

    static const _flush_t flush;

    template <typename T>
    friend error& operator<< (error& e, T const& s);

    friend error& operator<< (error& e, _flush_t const& s);

private:

    std::stringstream m_stream;
    std::string m_string;

};

template <typename T>
inline error& operator<< (error& e, T const& s) {
    e.m_stream << s;
    return e;
}

inline error& operator<< (error& e, error::_flush_t const& f) {
    e.m_string = e.m_stream.str();
    return e;
}

}

#endif
