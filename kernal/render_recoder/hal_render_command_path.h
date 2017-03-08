#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Path_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Path_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>

#include "hal_render_command_draw.h"

namespace kernal {
    class hal_render_command_path
        : public hal_render_command_draw {
    public:
        using _parent = hal_render_command_draw;
        using hal_render_command_draw::hal_render_command_draw;

    public:
        // path render begin
        bool begin_path();

        // path render close
        void close_path();

        // path render clear
        void clear_path();

        // path render
        void move_to(const hal_point pt);
        void line_to(const hal_point pt);
        void quad_to(const hal_point pt0, const hal_point pt1);
        void cubi_to(const hal_point pt0, const hal_point pt1, const hal_point pt2);
        bool fill_path(const hal_color clr, bool aa);
        bool stroke_path(const hal_color clr, bool width, bool aa);
        bool stroke_fill_path(const hal_color clr, bool width, bool aa);
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Path_H_
