#include "hal_render_surface_canvas.h"
using namespace kernal;

hal_render_surface_canvas::hal_render_surface_canvas(
    const hal_size& size) {
    hal_render_surface_canvas::resize(size);
}

hal_render_surface_canvas::~hal_render_surface_canvas() {

}

void hal_render_surface_canvas::resize(const hal_size& size) {
    surface_ = sk_sp<SkSurface>(
        SkSurface::MakeRasterN32Premul(size.width_, size.height_));
}

void hal_render_surface_canvas::capture_to_file(const char* file) {

    do {
        if (nullptr == file || !surface_) {
            break;
        }

        sk_sp<SkImage> _texture(surface_->makeImageSnapshot());
        if (!_texture) {
            break;
        }

        sk_sp<SkData> _data(_texture->encode());
        if (!_data) {
            break;
        }

        SkFILEWStream _out_stream(file);
        _out_stream.write(_data->data(), _data->size());
    } while (0);
}

hal_size hal_render_surface_canvas::size() const {
    if (!surface_) {
        return hal_size_make(0, 0);
    }
    return hal_size_make(surface_->width(), surface_->height());
}

SkCanvas* hal_render_surface_canvas::raw_unsafe_canvas() {
    if (!surface_) {
        return nullptr;
    }
    return surface_->getCanvas();
}
