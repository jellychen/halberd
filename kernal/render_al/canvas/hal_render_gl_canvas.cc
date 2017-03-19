#include "hal_render_gl_canvas.h"
using namespace kernal;

hal_render_gl_canvas::hal_render_gl_canvas(
    const hal_size& size, bool premul_alpha) {
    premul_alpha_ = premul_alpha;
    hal_render_gl_canvas::resize(size);
}

hal_render_gl_canvas::~hal_render_gl_canvas() {

}

void hal_render_gl_canvas::resize(const hal_size& size) {
    size_.width_ = size.width_; size_.height_ = size.height_;
    const GrGLInterface* interface = nullptr;
    GrContext* context = GrContext::Create(
        kOpenGL_GrBackend, (GrBackendContext)interface);
    if (premul_alpha_) {
        surface_ = SkSurface::MakeRenderTarget(context,
            SkBudgeted::kNo, SkImageInfo::Make(size_.width_,
                size_.height_, kN32_SkColorType, kPremul_SkAlphaType));
    } else {
        surface_ = SkSurface::MakeRenderTarget(context,
            SkBudgeted::kNo, SkImageInfo::Make(size_.width_,
                size_.height_, kN32_SkColorType, kUnpremul_SkAlphaType));
    }
}

void hal_render_gl_canvas::capture_to_file(const char* file) {
    if (nullptr == file || !surface_) {
        return;
    }
    sk_sp<SkImage> img(surface_->makeImageSnapshot());
    if (!img) return;
    sk_sp<SkData> texture(img->encode());
    if (!texture) return;
    SkFILEWStream out(file);
    (void)out.write(texture->data(), texture->size());
}

hal_size hal_render_gl_canvas::size() const {
    return size_;
}

SkCanvas* hal_render_gl_canvas::raw_unsafe_canvas() {
    if (surface_) {
        return surface_->getCanvas();
    }
    return nullptr;
}
