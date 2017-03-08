#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Text_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Text_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>
#include <render_al/text/hal_render_text_attr.h>
#include <render_al/text/hal_render_text_font.h>

#include "hal_render_command_buffer.h"
#include "hal_render_command_string.h"

namespace kernal {
    class hal_render_command_text final {
    public:
        hal_render_command_text(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_render_command_text();

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
        bool draw_oneline(const char* text, size_t len,
            hal_point loc, hal_color clr, uint8_t alpha);

        // note: draw multiLine
        bool draw_multiLine(const char* text,
            size_t len, hal_rect rect, float line_s,
            hal_point loc, hal_color clr, uint8_t alpha);

    public:
        hal_render_text_attr text_attr_;

    protected:
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Text_H_
