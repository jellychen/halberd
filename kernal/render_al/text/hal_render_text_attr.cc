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
