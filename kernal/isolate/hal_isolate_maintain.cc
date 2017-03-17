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

    // note: create
    document_ = hal_creator<hal_document>::instance(command_buffer_);

    // note: create thread;
    thread_ = std::thread([this] {
        while (false == should_exit_) {
            task_queue_->wait_and_run_runable(this);
        }
    });
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

bool hal_isolate_maintain::load_buffer_data(const char* buffer, uint32_t len) {
    return true;
}

bool hal_isolate_maintain::resize_document_view_size(hal_size& size) {
    if (document_) {
        return document_->resize_view_size(size);
    }
    return false;
}

bool hal_isolate_maintain::capture_canvas_to_file(const char* name) {
    if (document_) {
        return document_->capture_canvas_to_file(name);
    }
    return false;
}

void hal_isolate_maintain::post(
    std::function<void(hal_isolate_maintain*)> runable) {
    task_queue_->post(runable);
}
