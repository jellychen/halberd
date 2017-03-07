#ifndef Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_
#define Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <render_al/hal_render_require.h>
#include <render_al/context/hal_render_context.h>

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
        // note: measure as one line
        bool measure_size(const char*, size_t len, hal_size*);

        // note: measure as maybe mutilines
        bool measure_size(const char*, size_t len, float max_w, hal_size*);

        // note: draw one line
        bool draw_oneline(std::shared_ptr<hal_render_context>&,
                const char* text, size_t len, hal_point loc, hal_color clr);

        // note: draw multiLine
        bool draw_multiLine(std::shared_ptr<hal_render_context>&,
                const char* text, size_t len, hal_rect rect, float line_s,
                hal_point loc, hal_color clr);

    public:
        bool aa_ = false;
        float text_size_ = 13;
        hal_color_t text_color_;
        bool under_line_ = false, strike_line_ = false;
        std::shared_ptr<hal_render_text_font> font_;
    };
}
#endif//Halberd_Kernal_Render_Al_Text_Hal_Render_Text_Attr_H_
