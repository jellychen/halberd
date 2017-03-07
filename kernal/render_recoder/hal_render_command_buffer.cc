#include "hal_render_command_buffer.h"
using namespace kernal;

hal_render_command_buffer::hal_render_command_buffer() {

}

hal_render_command_buffer::~hal_render_command_buffer() {

}

void hal_render_command_buffer::commit(hal_render_command& command) {
    if (command) {
        command_queue_.push(command);
    }
}

void hal_render_command_buffer::run(
    std::shared_ptr<hal_render_context>& context) {
    if (context) {
        while (command_queue_.size() > 0) {
            command_queue_.front()(context);
            command_queue_.pop();
        }
    }
}
