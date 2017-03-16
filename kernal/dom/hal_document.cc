#include "hal_document.h"
using namespace kernal;

hal_document::hal_document() {
}

hal_document::hal_document(
    std::shared_ptr<hal_render_command_buffer>& command_buffer) {
    command_buffer_ = command_buffer;
}

hal_document::~hal_document() {
}

std::shared_ptr<hal_render_command_buffer> hal_document::command_buffer() {
    return command_buffer_;
}

bool hal_document::layout(hal_size& size) {
    return true;
}

bool hal_document::resize_view_size(hal_size& size) {
    // note: notify raster thread, notify resize canvas
    if (command_buffer_) {
        hal_size new_size = size;
        hal_render_command command = [new_size](
            std::shared_ptr<hal_render_context>& context) {
            if (context) {
                context->resize(new_size);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

// note: capture current canvas
bool hal_document::capture_canvas_to_file(const char* name) {
    if (nullptr == name || !command_buffer_) {
        return false;
    }

    std::string std_name_str(name);
    std::function<void(std::shared_ptr<hal_render_context>&)> runable
        = [std_name_str] (std::shared_ptr<hal_render_context>& context) {
        if (context) context->capture_to_file(std_name_str.c_str());
    };
    std_name_str = ""; command_buffer_->commit(runable);
    return true;
}
