#include "hal_render_text_font.h"
using namespace kernal;

hal_render_text_font::hal_render_text_font() {

}

hal_render_text_font::~hal_render_text_font() {

}

bool hal_render_text_font::make_normal(const char* name) {
    SkFontStyle style(SkFontStyle::kExtraLight_Weight,
        SkFontStyle::kNormal_Width, SkFontStyle::kUpright_Slant);
    type_face_ = SkTypeface::MakeFromName(name, style);
    return (bool)type_face_;
}

bool hal_render_text_font::make_bold(const char* name) {
    SkFontStyle style(SkFontStyle::kBold_Weight,
        SkFontStyle::kExpanded_Width, SkFontStyle::kUpright_Slant);
    type_face_ = SkTypeface::MakeFromName(name, style);
    return (bool)type_face_;
}

bool hal_render_text_font::make_italic(const char* name) {
    SkFontStyle style(SkFontStyle::kNormal_Weight,
        SkFontStyle::kNormal_Width, SkFontStyle::kItalic_Slant);
    type_face_ = SkTypeface::MakeFromName(name, style);
    return (bool)type_face_;
}

bool hal_render_text_font::make_bold_italic(const char* name) {
    SkFontStyle style(SkFontStyle::kBold_Weight,
        SkFontStyle::kExpanded_Width, SkFontStyle::kItalic_Slant);
    type_face_ = SkTypeface::MakeFromName(name, style);
    return (bool)type_face_;
}

bool hal_render_text_font::make_default_normal() {
    type_face_ = SkTypeface::MakeDefault(SkTypeface::kNormal);
    return (bool)type_face_;
}

bool hal_render_text_font::make_default_bold() {
    type_face_ = SkTypeface::MakeDefault(SkTypeface::kBold);
    return (bool)type_face_;
}

bool hal_render_text_font::make_default_italic() {
    type_face_ = SkTypeface::MakeDefault(SkTypeface::kItalic);
    return (bool)type_face_;
}

bool hal_render_text_font::make_default_bold_italic() {
    type_face_ = SkTypeface::MakeDefault(SkTypeface::kBoldItalic);
    return (bool)type_face_;
}
