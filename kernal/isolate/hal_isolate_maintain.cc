#include "hal_isolate_maintain.h"
using namespace kernal;

hal_isolate_maintain::hal_isolate_maintain(
    std::shared_ptr<hal_render_command_buffer>& command_buffer)
    : command_buffer_(command_buffer) {
    // note: task queue
    task_queue_ = hal_creator<hal_isolate_task_queue>::instance();
    auto handler = std::dynamic_pointer_cast<hal_isolate_handler>(task_queue_);
    std::weak_ptr<hal_isolate_handler> weak_handler(handler);
    hal_singleton<hal_isolate_handler_fetcher>::share().attach(weak_handler);

    // note: create thread;
    thread_ = std::thread([this] {
        while (false == should_exit_) {
            task_queue_->wait_and_run_runable(this);
        }
    });

    //std::chrono::milliseconds timespan(50); // or whatever
    //std::this_thread::sleep_for(timespan);
}

hal_isolate_maintain::~hal_isolate_maintain() {
    should_exit_ = true;
    task_queue_->weak_up_thread();
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
    task_queue_->post(runable);
}
