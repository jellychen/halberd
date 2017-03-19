#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Draw_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Draw_H_

#include "base/hal_inct.h"
#include "render_al/context/hal_render_context.h"
#include "hal_render_command_base.h"

namespace kernal {
    class hal_render_command_draw
        : public hal_render_command_base
    {
    public:
        using _parent = hal_render_command_base;
        using hal_render_command_base::hal_render_command_base;

    public:
        // erase with color
        bool erase(const hal_color& clr);

        // stroke shape like line rect ...
        bool draw_line(const hal_point& pt0,
            const hal_point& pt1, float width, const hal_color& clr, bool aa);
        bool draw_oval(const hal_rect& rect,
            float width, const hal_color& clr, bool aa);
        bool draw_rect(const hal_rect& rect,
            float width, const hal_color& clr, bool aa);
        bool draw_round_rect(const hal_rect& rect, float rx,
            float ry, float width, const hal_color& clr, bool aa);

        // fill shape like rect roundrect ...
        bool fill_oval(const hal_rect& rect, const hal_color& clr, bool aa);
        bool fill_rect(const hal_rect& rect, const hal_color& clr, bool aa);
        bool fill_round_rect(const hal_rect& rect, float rx, float ry, const hal_color& clr, bool aa);

        // clip
        bool clip_union(const hal_rect& rect, bool aa);
        bool clip_replace(const hal_rect& rect, bool aa);
        bool clip_intersect(const hal_rect& rect, bool aa);
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Draw_H_
