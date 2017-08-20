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

class io_socket : public io_base {
public:

    io_socket();
    virtual ~io_socket();
    virtual bool valid() override;

protected:

    virtual size_t avail() const override;

private:

    bool m_connected;

};

}
}
}

#endif
