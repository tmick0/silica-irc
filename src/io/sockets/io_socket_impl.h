#ifndef io_socket_impl_h_
#define io_socket_impl_h_

#include <silica/io/sockets/io_socket.h>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

namespace silica {
namespace io {
namespace sockets {

template <typename Detail>
class io_socket_impl : public io_socket {
public:
    io_socket_impl() {
        if ((m_fd = socket(Detail::domain, Detail::type, 0)) < 0) {
            make_error("socket()");
        }
    };

protected:
    virtual size_t resolve(std::string const& hostname, std::string const& port, sockaddr& sock_addr) override {
        addrinfo hints;
        memset(&hints, 0, sizeof(addrinfo));
        hints.ai_family = Detail::domain;
        hints.ai_socktype = Detail::type;

        addrinfo* result;
        int err;
        if ((err = getaddrinfo(hostname.c_str(), port.c_str(), &hints, &result)) != 0) {
            make_error("getaddrinfo(): returned " << err);
        }

        // TODO: cache getaddrinfo() results, iterate on subsequent calls to resolve()?
        const size_t addrlen = result->ai_addrlen;
        memcpy(&sock_addr, result->ai_addr, addrlen);

        freeaddrinfo(result);
        return addrlen;
    }
};
}
}
}

#endif
