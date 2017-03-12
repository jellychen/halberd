#include "hal_isolate_handler.h"
using namespace kernal;

thread_local std::weak_ptr<hal_isolate_handler> __thread_local_handler;

bool hal_isolate_handler_fetcher::attach(
    std::weak_ptr<hal_isolate_handler>& handler) {
    __thread_local_handler = handler;
    if (!__thread_local_handler.expired()) {
        printf("%s\n", "~~~~");
    }
    return true;
}

std::weak_ptr<hal_isolate_handler> hal_isolate_handler_fetcher::current() {
    return __thread_local_handler;
}
