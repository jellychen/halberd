#ifndef Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_
#define Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <render_al/hal_render_require.h>

#include "hal_render_text_font.h"

namespace kernal {
    class hal_render_text_attr final {
    public:
        hal_render_text_attr();
        virtual ~hal_render_text_attr();

    public:
        bool is_bold() const;
        bool is_italic() const;
        bool is_have_font() const;
        bool is_have_under_line() const;
        bool is_have_strike_line() const;

    public:
        bool measure_size(const char*, size_t len, hal_size*);

    public:
        bool aa_ = false;
        float text_size_ = 13; hal_color_t text_color_;
        bool under_line_ = false; bool strike_line_ = false;
        std::shared_ptr<hal_render_text_font> font_;
    };
}
#endif//Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_
