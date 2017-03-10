#include "hal_render_command_buffer.h"
using namespace kernal;

hal_render_command_buffer::hal_render_command_buffer(
    bool multi_thread): is_multi_thread(multi_thread),
    in_(&(command_queue_[0])), out_(&(command_queue_[1])) {
}

hal_render_command_buffer::~hal_render_command_buffer() {

}

void hal_render_command_buffer::commit(
    hal_render_command& command) {
    if (!command) {
        return;
    }

    if (false == is_multi_thread) {
        in_->push(command);
    } else {
        std::unique_lock<std::mutex> lock(mutex_);
        in_->push(command); signal_ = true; lock.unlock();
        condition_.notify_one();
    }
}

void hal_render_command_buffer::run(
    std::shared_ptr<hal_render_context>& context) {
    if (context) {
        while (in_->size() > 0) {
            in_->front()(context); in_->pop();
        }
    }
}

void hal_render_command_buffer::run_in_thread(
    std::shared_ptr<hal_render_context>& context) {
    if (context) {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this]{ return this->signal_;});
        signal_ = false; std::swap(in_, out_);
        lock.unlock();

        while (out_->size() > 0) {
            out_->front()(context); out_->pop();
        }
    }
}

void hal_render_command_buffer::wake_up_thread() {
    std::unique_lock<std::mutex> lock(mutex_);
    signal_ = true; lock.unlock();
    condition_.notify_one();
}
