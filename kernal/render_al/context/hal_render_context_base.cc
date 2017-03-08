#include "hal_render_context_base.h"
using namespace kernal;

hal_render_context_base::hal_render_context_base
            (std::shared_ptr<hal_render_canvas>& canvas) {
    canvas_ = canvas;
}

hal_render_context_base::~hal_render_context_base() {

}

void hal_render_context_base::capture_to_file(const char* file) {
    if (nullptr != file && canvas_) {
        canvas_->capture_to_file(file);
    }
}

bool hal_render_context_base::erase(const hal_color& clr) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    canvas->clear(SkColorSetARGBMacro(clr.a_, clr.r_, clr.g_, clr.b_));
    return true;
}

bool hal_render_context_base::draw_line(const hal_point& pt0,
    const hal_point& pt1, float width, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStrokeWidth(width);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawLine(pt0.x_, pt0.y_, pt1.x_, pt1.y_, paint);
    return true;
}

bool hal_render_context_base::draw_oval(
    const hal_rect& rect, float width, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStrokeWidth(width);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawOval(__convert_to_t(rect), paint);
    return true;
}

bool hal_render_context_base::draw_rect(
    const hal_rect& rect, float width, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStrokeWidth(width);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawRect(__convert_to_t(rect), paint);
    return true;
}

bool hal_render_context_base::draw_round_rect(const hal_rect& rect,
    float rx, float ry, float width, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStrokeWidth(width);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawRoundRect(__convert_to_t(rect), rx, ry, paint);
    return true;
}

bool hal_render_context_base::fill_oval(
    const hal_rect& rect, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawOval(__convert_to_t(rect), paint);
    return true;
}

bool hal_render_context_base::fill_rect(
    const hal_rect& rect, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawRect(__convert_to_t(rect), paint);
    return true;
}

bool hal_render_context_base::fill_round_rect(
    const hal_rect& rect, float rx, float ry, const hal_color& clr, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    canvas->drawRoundRect(__convert_to_t(rect), rx, ry, paint);
    return true;
}

SkCanvas* hal_render_context_base::raw_unsafe_canvas() {
    if (canvas_) {
        return canvas_->raw_unsafe_canvas();
    }
    return nullptr;
}
