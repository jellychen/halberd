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
