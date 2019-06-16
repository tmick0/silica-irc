#ifndef context_state_h_
#define context_state_h_

namespace silica {
namespace client {

enum class context_state { INITIALIZED = 0, CONNECTING, CONNECTED, DISCONNECTED, ERROR };
}
}

#endif
