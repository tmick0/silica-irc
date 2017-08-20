#ifndef io_socket_h_
#define io_socket_h_

#include <unordered_map>
#include <vector>
#include <cstdint>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "common/error.h"
#include "io/io_base.h"

namespace silica {
namespace io {
namespace sockets {

class io_socket: public io_base {
public:

    io_socket();
    void connect(std::string const& hostname, std::string const& port);

    virtual ~io_socket();
    virtual bool valid() override;

protected:

    virtual size_t avail() const override;

    /* To be implemented by derived classes */
    virtual size_t resolve(std::string const& hostname, std::string const& port, sockaddr& sock_addr) = 0;

private:

    bool m_connected;

};

}
}
}

#endif
