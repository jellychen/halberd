#include "hal_render_mem_canvas.h"
using namespace kernal;

hal_render_mem_canvas::hal_render_mem_canvas(
    const hal_size& size, bool premul_alpha)
    : premul_alpha_(premul_alpha) {
    hal_render_mem_canvas::resize(size);
}

hal_render_mem_canvas::~hal_render_mem_canvas() {
    if (nullptr != mem_buffer_) {
        delete[] mem_buffer_;
    }

    if (nullptr != canvas_) {
        delete canvas_;
    }
}

void hal_render_mem_canvas::resize(const hal_size& size) {
    if (nullptr != mem_buffer_) {
        delete[] mem_buffer_;
    }

    if (nullptr != canvas_) {
        delete canvas_;
    }

    mem_buffer_ = nullptr; canvas_ = nullptr;
    size_.width_ = size.width_; size_.height_ = size.height_;
    uint32_t buffer_size = size_.width_ * size_.height_;
    if (0 >= buffer_size) return;
    mem_buffer_ = new(std::nothrow)uint32_t[buffer_size];
    if (mem_buffer_) {
        ::memset(mem_buffer_, 0, sizeof(uint32_t) * buffer_size);
    }

    if (premul_alpha_) {
        bitmap_.setInfo(SkImageInfo::Make(size_.width_,
            size_.height_, kN32_SkColorType, kPremul_SkAlphaType));
    } else {
        bitmap_.setInfo(SkImageInfo::Make(size_.width_,
            size_.height_, kN32_SkColorType, kUnpremul_SkAlphaType));
    }
    bitmap_.setPixels(mem_buffer_);
    canvas_ = new(std::nothrow) SkCanvas(bitmap_);
}

void hal_render_mem_canvas::capture_to_file(const char* file) {
    if (nullptr == file || nullptr == mem_buffer_) {
        return;
    }
    
    sk_sp<SkImage> texture;
    uint32_t buffer_size = size_.width_ * size_.height_;
    sk_sp<SkData> data = SkData::MakeWithCopy(
        mem_buffer_, buffer_size * sizeof(uint32_t));

    if (premul_alpha_) {
        texture = SkImage::MakeRasterData(
            SkImageInfo::Make(size_.width_, size_.height_,
            kN32_SkColorType, kPremul_SkAlphaType), data,
            size_.width_ * sizeof(uint32_t));
    } else {
        texture = SkImage::MakeRasterData(
           SkImageInfo::Make(size_.width_, size_.height_,
           kN32_SkColorType, kUnpremul_SkAlphaType), data,
           size_.width_ * sizeof(uint32_t));
    }

    if (texture) {
        sk_sp<SkData> texture_data(texture->encode());
        if (texture_data) {
            SkFILEWStream _out_stream(file);
            _out_stream.write(texture_data->data(), texture_data->size());
        }
    }
}

hal_size hal_render_mem_canvas::size() const {
    return size_;
}

SkCanvas* hal_render_mem_canvas::raw_unsafe_canvas() {
    return canvas_;
}
