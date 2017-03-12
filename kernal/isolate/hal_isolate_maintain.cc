#include "hal_isolate_maintain.h"
using namespace kernal;

hal_isolate_maintain::hal_isolate_maintain(
    std::shared_ptr<hal_render_command_buffer>& command_buffer)
    : command_buffer_(command_buffer) {
    thread_ = std::thread([this] {
        this->internal_thread_main();
    });
    //std::chrono::milliseconds timespan(50); // or whatever
    //std::this_thread::sleep_for(timespan);
}

hal_isolate_maintain::~hal_isolate_maintain() {
    should_exit_ = true;
    handler_.weak_up_thread();
    thread_.join();
}

bool hal_isolate_maintain::load_url(const char* url) {
    if (nullptr == url) {
        return false;
    }
    return true;
}

bool hal_isolate_maintain::load_from_file(const char* name) {
    if (nullptr == name) {
        return false;
    }
    return true;
}

void hal_isolate_maintain::post(
    std::function<void(hal_isolate_maintain*)>& runable) {
    handler_.post(runable);
}

void hal_isolate_maintain::internal_thread_main() {
    while (false == should_exit_) {
        handler_.wait_and_run_runable(this);
    }
}
