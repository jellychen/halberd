#include "hal_render_texture.h"
using namespace kernal;

hal_render_texture::hal_render_texture() {

}

hal_render_texture::~hal_render_texture() {

}

bool hal_render_texture::clear() {
    texture_ = nullptr; return true;
}

bool hal_render_texture::is_have_data() const {
    return (bool) texture_;
}

bool hal_render_texture::load_file(const char* file) {
    hal_render_texture::clear();
    if (nullptr == file) {
        return false;
    }

    sk_sp<SkData> data(SkData::MakeFromFileName(file));
    texture_ = SkImage::MakeFromEncoded(data);
    return (bool)texture_;
}

bool hal_render_texture::load_buffer(const char* buffer, uint32_t size) {
    hal_render_texture::clear();
    if (nullptr == buffer || 0 == size) {
        return false;
    }

    sk_sp<SkData> data(SkData::MakeWithoutCopy((void*)buffer, (size_t)size));
    texture_ = SkImage::MakeFromEncoded(data);
    return (bool)texture_;
}

hal_size hal_render_texture::size() const {
    if (!texture_) {
        return hal_size_make(0, 0);
    }

    float width = texture_->width();
    float height = texture_->height();
    return hal_size_make(width, height);
}

bool hal_render_texture::draw(std::shared_ptr
    <hal_render_context>& context, uint8_t alpha, bool aa, float l, float t) {
        if (!context) {
            return false;
        }

        auto canvas = context->raw_unsafe_canvas();
        if (nullptr == canvas) {
            return false;
        }

        if (0 == alpha) {
            return true;
        }

        SkPaint paint;
        paint.setAlpha(alpha);
        paint.setAntiAlias(aa);
        canvas->drawImage(texture_, l, t, &paint);
        return true;
}

bool hal_render_texture::draw(std::shared_ptr<hal_render_context>& context,
    uint8_t alpha, bool aa, const hal_rect& src, const hal_rect& dest) {
    if (!context) {
        return false;
    }

    auto canvas = context->raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    if (0 == alpha) {
        return true;
    }

    SkPaint paint;
    paint.setAlpha(alpha);
    paint.setAntiAlias(aa);
    canvas->drawImageRect(texture_.get(),
        __convert_to_t(src), __convert_to_t(dest), &paint);
    return true;
}
