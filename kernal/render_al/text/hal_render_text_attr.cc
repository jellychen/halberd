#include "hal_render_text_attr.h"
using namespace kernal;

hal_render_text_attr::hal_render_text_attr() {

}

hal_render_text_attr::~hal_render_text_attr() {

}

bool hal_render_text_attr::is_bold() const {
    if (font_ && font_->type_face_) {
        return font_->type_face_->isBold();
    }
    return false;
}

bool hal_render_text_attr::is_italic() const {
    if (font_ && font_->type_face_) {
        return font_->type_face_->isItalic();
    }
    return false;
}

bool hal_render_text_attr::is_have_font() const {
    return (bool)(font_ && font_->type_face_);
}

bool hal_render_text_attr::is_have_under_line() const {
    return under_line_;
}

bool hal_render_text_attr::is_have_strike_line() const {
    return strike_line_;
}

bool hal_render_text_attr::measure_size(
    const char* text, size_t len, hal_size* size) {
    if (nullptr == text || 0 == len || nullptr == size) {
        return false;
    }

    SkPaint paint; SkRect rect;
    paint.setAntiAlias(aa_);
    paint.setTextSize(text_size_);
    if (font_) {
        paint.setTypeface(font_->type_face_);
    }
    if (under_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
    }
    if (strike_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
    }

    paint.measureText(text, len, &rect);
    size->width_ = rect.width();
    size->height_ = rect.height();
    return true;
}

bool hal_render_text_attr::measure_size(
    const char* text, size_t len, float max_w, hal_size* size) {
    if (nullptr == text || 0 == len || nullptr == size) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa_);
    paint.setTextSize(text_size_);
    if (font_) {
        paint.setTypeface(font_->type_face_);
    }
    if (under_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
    }
    if (strike_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
    }

    float sub_h = 0;
    size_t current = 0; SkRect rect;
    while (current < len) {
        size_t break_len = paint.breakText(text + current, len - current, max_w);
        paint.measureText(text + current, break_len, &rect);
        current += break_len; sub_h += rect.height();
    }
    size->width_ = max_w; size->height_ = sub_h;
    return true;
}

bool hal_render_text_attr::draw_oneline(
    std::shared_ptr<hal_render_context>& context,
    const char* text, size_t len, hal_point loc, hal_color clr) {
    if (!context || nullptr == text || !context->raw_unsafe_canvas()) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa_);
    paint.setTextSize(text_size_);
    paint.setTextAlign(SkPaint::kLeft_Align);
    paint.setTextEncoding(SkPaint::kUTF8_TextEncoding);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    if (font_) {
        paint.setTypeface(font_->type_face_);
    }
    if (under_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
    }
    if (strike_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
    }

    SkPaint::FontMetrics font_metrics;
    paint.getFontMetrics(&font_metrics);
    loc.y_ += font_metrics.fLeading - font_metrics.fAscent;
    context->raw_unsafe_canvas()->drawText(text, len, loc.x_, loc.y_, paint);
    return true;
}

bool hal_render_text_attr::draw_multiLine(
    std::shared_ptr<hal_render_context>& context,
    const char* text, size_t len, hal_rect rect, float line_s,
    hal_point loc, hal_color clr) {
    if (!context || nullptr == text || !context->raw_unsafe_canvas()) {
        return false;
    }

    SkPaint paint;
    paint.setAntiAlias(aa_);
    paint.setTextSize(text_size_);
    paint.setTextAlign(SkPaint::kLeft_Align);
    paint.setTextEncoding(SkPaint::kUTF8_TextEncoding);
    paint.setARGB(clr.a_, clr.r_, clr.g_, clr.b_);
    if (font_) {
        paint.setTypeface(font_->type_face_);
    }
    if (under_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
    }
    if (strike_line_) {
        paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
    }

    SkPaint::FontMetrics font_metrics;
    float line_default_s = paint.getFontMetrics(&font_metrics);
    size_t current = 0; SkRect measure_rect; float current_h = 0;
    while (current < len) {
        if (current_h < rect.height_) {
            size_t break_len = paint.breakText(text + current, len - current, rect.width_);
            paint.measureText(text + current, break_len, &measure_rect);
            float loc_postion_y = rect.y_ + current_h
                + font_metrics.fLeading - font_metrics.fAscent;
            context->raw_unsafe_canvas()->drawText(
                text + current, break_len, rect.x_, loc_postion_y, paint);
            current += break_len; current_h += measure_rect.height() + line_s;
        } else {
            break;
        }
    }
    (void)(line_default_s);
    return true;
}
