#ifndef Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Font_H_
#define Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Font_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <render_al/hal_render_require.h>

namespace kernal {
    class hal_render_text_font final {
    public:
        hal_render_text_font();
        virtual ~hal_render_text_font();

    public:
        bool make_normal(const char*);
        bool make_bold(const char*);
        bool make_italic(const char*);
        bool make_bold_italic(const char*);

    public:
        bool make_default_normal();
        bool make_default_bold();
        bool make_default_italic();
        bool make_default_bold_italic();

    public:
        sk_sp<SkTypeface> type_face_;
    };
}
#endif//Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Font_H_
