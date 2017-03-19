#include "hal_render_command_text.h"
using namespace kernal;

hal_render_command_text::hal_render_command_text(
    std::shared_ptr<hal_render_command_buffer>& buffer):command_buffer_(buffer) {
}

hal_render_command_text::~hal_render_command_text() {
}

bool hal_render_command_text::is_bold() const {
    return text_attr_.is_bold();
}

bool hal_render_command_text::is_italic() const {
    return text_attr_.is_italic();
}

bool hal_render_command_text::is_have_font() const {
    return text_attr_.is_have_font();
}

bool hal_render_command_text::is_have_under_line() const {
    return text_attr_.is_have_under_line();
}

bool hal_render_command_text::is_have_strike_line() const {
    return text_attr_.is_have_strike_line();
}

bool hal_render_command_text::measure_size(
    const char* str, size_t len, hal_size* size) {
    return text_attr_.measure_size(str, len, size);
}

bool hal_render_command_text::measure_size(
    const char* str, size_t len, float max_w, hal_size* size) {
    return text_attr_.measure_size(str, len, max_w, size);
}

bool hal_render_command_text::draw_oneline(
    const char* text, size_t len, hal_point& loc,
    hal_color& clr, uint8_t alpha) {
    if (nullptr != text && 0 < len && command_buffer_) {

        // note: use for block capture
        bool aa = text_attr_.aa_;
        float text_size = text_attr_.text_size_;
        bool under_line = text_attr_.under_line_;
        bool strike_line = text_attr_.strike_line_;

        sk_sp<SkTypeface> type_face;
        if (text_attr_.font_) {
            type_face = text_attr_.font_->type_face_;
        }
        hal_render_command_string_t str(text, len);

        // note: block
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context && context->raw_unsafe_canvas()) {
                SkPaint paint;
                paint.setAntiAlias(aa);
                paint.setTextSize(text_size);
                paint.setTypeface(type_face);
                paint.setTextAlign(SkPaint::kLeft_Align);
                paint.setTextEncoding(SkPaint::kUTF8_TextEncoding);
                paint.setARGB(clr.a_ * alpha/255., clr.r_, clr.g_, clr.b_);

                if (under_line) {
                    paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
                }

                if (strike_line) {
                    paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
                }

                SkPaint::FontMetrics font_metrics;
                paint.getFontMetrics(&font_metrics);
                float h_start = loc.y_ + font_metrics.fLeading - font_metrics.fAscent;
                context->raw_unsafe_canvas()->drawText(str.c_str(), len, loc.x_, h_start, paint);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}

bool hal_render_command_text::draw_multiLine(
    const char* text, size_t len, hal_rect& rect, float line_s,
    hal_point& loc, hal_color& clr, uint8_t alpha) {
    if (nullptr != text && 0 < len && command_buffer_) {

        // note: use for block capture
        bool aa = text_attr_.aa_;
        float text_size = text_attr_.text_size_;
        bool under_line = text_attr_.under_line_;
        bool strike_line = text_attr_.strike_line_;

        sk_sp<SkTypeface> type_face;
        if (text_attr_.font_) {
            type_face = text_attr_.font_->type_face_;
        }
        hal_render_command_string_t str(text, len);

        // note: block
        hal_render_command command = [=](
            std::shared_ptr<hal_render_context>& context) {
            if (context && context->raw_unsafe_canvas()) {
                SkPaint paint;
                paint.setAntiAlias(aa);
                paint.setTextSize(text_size);
                paint.setTypeface(type_face);
                paint.setTextAlign(SkPaint::kLeft_Align);
                paint.setTextEncoding(SkPaint::kUTF8_TextEncoding);
                paint.setARGB(clr.a_ * alpha/255., clr.r_, clr.g_, clr.b_);

                if (under_line) {
                    paint.setFlags(paint.getFlags() | SkPaint::kUnderlineText_Flag);
                }

                if (strike_line) {
                    paint.setFlags(paint.getFlags() | SkPaint::kStrikeThruText_Flag);
                }

                SkPaint::FontMetrics font_metrics;
                float line_default_s = paint.getFontMetrics(&font_metrics);
                size_t current = 0; SkRect measure_rect; float current_h = 0;
                while (current < len) {
                    if (current_h < rect.height_) {
                        size_t break_len = paint.breakText(
                            str.c_str() + current, len - current, rect.width_);
                        paint.measureText(str.c_str() + current, break_len, &measure_rect);
                        float loc_postion_y = rect.y_ + current_h
                            + font_metrics.fLeading - font_metrics.fAscent;
                        context->raw_unsafe_canvas()->drawText(
                            str.c_str() + current, break_len, rect.x_, loc_postion_y, paint);
                        current += break_len; current_h += measure_rect.height() + line_s;
                    } else {
                        break;
                    }
                }
                (void)(line_default_s);
            }
        };
        command_buffer_->commit(command);
    }
    return true;
}
