#include "hal_render_command_texture.h"
using namespace kernal;

hal_render_command_texture::hal_render_command_texture() {

}

hal_render_command_texture::~hal_render_command_texture() {

}

bool hal_render_command_texture::clear() {
    return raw_texture_.clear();
}

bool hal_render_command_texture::is_have_data() const {
    return raw_texture_.is_have_data();
}

bool hal_render_command_texture::load_file(const char* file) {
    return raw_texture_.load_file(file);
}

bool hal_render_command_texture::load_buffer(
    const char* buffer, uint32_t size) {
    return raw_texture_.load_buffer(buffer, size);
}

hal_size hal_render_command_texture::size() const {
    return raw_texture_.size();
}

bool hal_render_command_texture::draw(
    uint8_t alpha, bool aa, float l, float t) {
    if (0 == alpha || !raw_texture_.texture_) {
        return true;
    }

    if (_parent::command_buffer_) {
        sk_sp<SkImage> texture = raw_texture_.texture_;
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context && context->raw_unsafe_canvas()) {
                SkPaint paint;
                paint.setAlpha(alpha); paint.setAntiAlias(aa);
                context->raw_unsafe_canvas()->drawImage(texture, l, t, &paint);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_texture::draw(
    uint8_t alpha, bool aa, const hal_rect src, const hal_rect dest) {
    if (0 == alpha || !raw_texture_.texture_) {
        return true;
    }

    if (_parent::command_buffer_) {
        sk_sp<SkImage> texture = raw_texture_.texture_;
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context && context->raw_unsafe_canvas()) {
                SkPaint paint;
                paint.setAlpha(alpha); paint.setAntiAlias(aa);
                context->raw_unsafe_canvas()->drawImageRect(
                    texture.get(), __convert_to_t(src), __convert_to_t(dest), &paint);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
