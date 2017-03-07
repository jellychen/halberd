#include "hal_render_command_string.h"
using namespace kernal;

hal_render_command_string_t::hal_render_command_string_t() {

}

hal_render_command_string_t::hal_render_command_string_t(const char* str) {
    hal_render_command_string_t::operator=(str);
}

hal_render_command_string_t::hal_render_command_string_t(
    const hal_render_command_string_t& command_string) {
    hal_render_command_string_t::operator=(command_string.c_str());
}

hal_render_command_string_t::~hal_render_command_string_t() {
    if (nullptr != raw_buffer_) {
        delete[] raw_buffer_;
    }
}

char* hal_render_command_string_t::c_str() const {
    return raw_buffer_;
}

hal_render_command_string_t& hal_render_command_string_t::operator=(
    const char* str) {
    if (nullptr != raw_buffer_) {
        delete[] raw_buffer_;
        raw_buffer_ = nullptr;
    }

    if (nullptr != str) {
        int len = strlen(str);
        if (len > 0) {
            raw_buffer_ = new(std::nothrow)char[len];
            if (nullptr != raw_buffer_) {
                memcpy(raw_buffer_, str, (size_t)len);
            }
        }
    }
    return *this;
}

hal_render_command_string_t& hal_render_command_string_t::operator=(
    const hal_render_command_string_t& command_string) {
    hal_render_command_string_t::operator=(command_string.c_str());
    return *this;
}
