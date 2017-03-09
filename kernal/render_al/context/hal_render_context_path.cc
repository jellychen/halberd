#define SK_SUPPORT_EXOTIC_CLIPOPS

#include "hal_render_context_path.h"
using namespace kernal;

void hal_render_context_path::clear_path() {
    path_.reset();
}

void hal_render_context_path::begin_path() {
    path_.reset();
}

void hal_render_context_path::close_path() {
    path_.close();
}

void hal_render_context_path::move_to(const hal_point& pt) {
    path_.moveTo(__convert_to_t(pt));
}

void hal_render_context_path::line_to(const hal_point& pt) {
    path_.lineTo(__convert_to_t(pt));
}

void hal_render_context_path::quad_to(
    const hal_point& pt0, const hal_point& pt1) {
    path_.quadTo(pt0.x_, pt0.y_, pt1.x_, pt1.y_);
}

void hal_render_context_path::cubi_to(
    const hal_point& pt0, const hal_point& pt1, const hal_point& pt2) {
    path_.cubicTo(pt0.x_, pt0.y_, pt1.x_, pt1.y_, pt2.x_, pt2.y_);
}

bool hal_render_context_path::fill_path(const hal_color& clr, bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        SkPaint paint;
        paint.setAntiAlias(aa);
        paint.setStyle(SkPaint::kFill_Style);
        paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
        raw_unsafe_canvas()->drawPath(path_, paint);
        return true;
    }
    return false;
}

bool hal_render_context_path::stroke_path(
    const hal_color& clr, bool width, bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        SkPaint paint;
        paint.setAntiAlias(aa);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
        raw_unsafe_canvas()->drawPath(path_, paint);
        return true;
    }
    return false;
}

bool hal_render_context_path::stroke_fill_path(
    const hal_color& clr, bool width, bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        SkPaint paint;
        paint.setAntiAlias(aa);
        paint.setStyle(SkPaint::kStrokeAndFill_Style);
        paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
        raw_unsafe_canvas()->drawPath(path_, paint);
        return true;
    }
    return false;
}

bool hal_render_context_path::clip_path_union(bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        raw_unsafe_canvas()->clipPath(path_, SkClipOp::kUnion, aa);
        return true;
    }
    return false;
}

bool hal_render_context_path::clip_path_replace(bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        raw_unsafe_canvas()->clipPath(path_, SkClipOp::kReplace, aa);
        return true;
    }
    return false;
}

bool hal_render_context_path::clip_path_intersect(bool aa) {
    if (nullptr != raw_unsafe_canvas()) {
        raw_unsafe_canvas()->clipPath(path_, SkClipOp::kIntersect, aa);
        return true;
    }
    return false;
}
