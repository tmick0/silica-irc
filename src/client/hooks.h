#ifndef hooks_h_
#define hooks_h_

#include <memory>

#include <silica/client/server_context.h>

namespace silica {
namespace client {

struct message_hook {
public:
    message_hook(std::shared_ptr<server_context> c, std::list<protocol::prototype> types) : context(c) {
        for (const auto& p : types) {
            hooks.emplace_back(c->add_hook(p, [this](std::shared_ptr<protocol::protobase> m) {
                std::unique_lock<std::mutex> l(lock);
                messages.emplace_back(m);
                cv.notify_one();
            }));
        }
    }

    ~message_hook() {
        for (server_context::hook_iterator_t h : hooks) {
            context->remove_hook(h);
        }
    }

    std::shared_ptr<protocol::protobase> consume(std::chrono::nanoseconds timeout) {
        std::shared_ptr<protocol::protobase> res;
        {
            std::unique_lock<std::mutex> l(lock);
            if (cv.wait_for(l, timeout, [this]() { return messages.size() > 0; })) {
                res = messages.front();
                messages.pop_front();
            }
        }
        return res;
    }

    std::shared_ptr<server_context> context;
    std::list<server_context::hook_iterator_t> hooks;
    std::list<std::shared_ptr<protocol::protobase>> messages;
    std::condition_variable cv;
    std::mutex lock;
};

}  // namespace client
}  // namespace silica

#endif