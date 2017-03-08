#include "hal_render_command_base.h"
using namespace kernal;

hal_render_command_base::hal_render_command_base(
    std::shared_ptr<hal_render_command_buffer>& buffer):command_buffer_(buffer) {

}

hal_render_command_base::~hal_render_command_base() {

}

void hal_render_command_base::capture_to_file(const char* file) {
    if (command_buffer_ && nullptr != file) {
        hal_render_command_string_t str = file;
        hal_render_command command = [str](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->capture_to_file(str.c_str());
            }
        };
        command_buffer_->commit(command);
    }
}
