#include "hal_render_path.h"
using namespace kernal;

hal_render_path::hal_render_path() {
}

hal_render_path::~hal_render_path() {
}

void hal_render_path::clear() {
    path_.reset();
}

void hal_render_path::move_to(const hal_point& pt) {
    path_.moveTo(__convert_to_t(pt));
}

void hal_render_path::line_to(const hal_point& pt) {
    path_.lineTo(__convert_to_t(pt));
}

void hal_render_path::quad_to(const hal_point& pt0, const hal_point& pt1) {
    path_.quadTo(pt0.x_, pt0.y_, pt1.x_, pt1.y_);
}

void hal_render_path::cubi_to(const hal_point& pt0, const hal_point& pt1, const hal_point& pt2) {
    path_.cubicTo(pt0.x_, pt0.y_, pt1.x_, pt1.y_, pt2.x_, pt2.y_);
}

void hal_render_path::close() {
    path_.close();
}

bool hal_render_path::fill(
    std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool aa) {
    if (!context || !context->raw_unsafe_canvas()) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    context->raw_unsafe_canvas()->drawPath(path_, paint);
    return true;
}

bool hal_render_path::stroke(
    std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool width, bool aa) {
    if (!context || !context->raw_unsafe_canvas()) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    context->raw_unsafe_canvas()->drawPath(path_, paint);
    return true;
}

bool hal_render_path::stroke_fill(
    std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool width, bool aa) {
    if (!context || !context->raw_unsafe_canvas()) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa);
    paint.setStyle(SkPaint::kStrokeAndFill_Style);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    context->raw_unsafe_canvas()->drawPath(path_, paint);
    return true;
}
