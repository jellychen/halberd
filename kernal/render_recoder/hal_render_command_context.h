#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>

#include "hal_render_command_buffer.h"
#include "hal_render_command_string.h"

namespace kernal {
    class hal_render_command_context final {
    public:
        hal_render_command_context(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_render_command_context();

    public:
        void capture_to_file(const char* file);

    public:
        // erase with color
        bool erase(const hal_color clr);

        // stroke shape
        // like line rect ...
        bool draw_line(const hal_point pt0,
            const hal_point pt1, float width, const hal_color clr, bool aa);
        bool draw_oval(const hal_rect rect,
            float width, const hal_color clr, bool aa);
        bool draw_rect(const hal_rect rect,
            float width, const hal_color clr, bool aa);
        bool draw_round_rect(const hal_rect rect, float rx,
            float ry, float width, const hal_color clr, bool aa);

        // fill shape
        // like rect roundrect ...
        bool fill_oval(const hal_rect rect, const hal_color clr, bool aa);
        bool fill_rect(const hal_rect rect, const hal_color clr, bool aa);
        bool fill_round_rect(const hal_rect rect, float rx, float ry, const hal_color clr, bool aa);

    public:
        // clip
        bool clip_union(const hal_rect rect, bool aa);
        bool clip_replace(const hal_rect rect, bool aa);
        bool clip_intersect(const hal_rect rect, bool aa);

    public:
        // state
        bool save_state();
        bool restore_state();
        bool rotate(float d);
        bool skew(float x, float y);
        bool scale(float x, float y);
        bool translate(float x, float y);
        bool camera_rotate(float x, float y, float z);
        bool camera_translate(float x, float y, float z);

    public:
        // path render
        bool begin_path();
        void close_path();
        void move_to(const hal_point pt);
        void line_to(const hal_point pt);
        void quad_to(const hal_point pt0, const hal_point pt1);
        void cubi_to(const hal_point pt0, const hal_point pt1, const hal_point pt2);
        bool fill_path(const hal_color clr, bool aa);
        bool stroke_path(const hal_color clr, bool width, bool aa);
        bool stroke_fill_path(const hal_color clr, bool width, bool aa);

    private:
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_
