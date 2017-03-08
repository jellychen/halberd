#include "hal_render_command_buffer.h"
using namespace kernal;

hal_render_command_buffer::hal_render_command_buffer(
    bool multi_thread)
    :in_(&command_queue_[0]), out_(&command_queue_[1])
    ,is_multi_thread(multi_thread){
}

hal_render_command_buffer::~hal_render_command_buffer() {

}

void hal_render_command_buffer::commit(
    hal_render_command& command) {
    if (command) {
        in_->push(command);
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

}
