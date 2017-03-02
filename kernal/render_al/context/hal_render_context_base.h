#ifndef Halberd_Kernal_Render_Al_Context_Hal_Render_Context_base_H_
#define Halberd_Kernal_Render_Al_Context_Hal_Render_Context_base_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <render_al/hal_render_require.h>
#include <render_al/canvas/hal_render_canvas.h>

namespace kernal
{
    class hal_render_path;
    class hal_render_texture;

    class hal_render_context_base {
    public:
        friend class hal_render_path;
        friend class hal_render_texture;
        hal_render_context_base(std::shared_ptr<hal_render_canvas>&);
        virtual ~hal_render_context_base();

    public:
        void capture_to_file(const char* file);

    public:
        // erase with color
        bool erase(const hal_color& clr);

        // stroke shape
        // like line rect ...
        bool draw_line(const hal_point& pt0,
            const hal_point& pt1, float width, const hal_color& clr, bool aa);
        bool draw_oval(const hal_rect& rect,
            float width, const hal_color& clr, bool aa);
        bool draw_rect(const hal_rect& rect,
            float width, const hal_color& clr, bool aa);
        bool draw_round_rect(const hal_rect& rect, float rx,
            float ry, float width, const hal_color& clr, bool aa);

        // fill shape
        // like rect roundrect ...
        bool fill_oval(const hal_rect& rect, const hal_color& clr, bool aa);
        bool fill_rect(const hal_rect& rect, const hal_color& clr, bool aa);
        bool fill_round_rect(const hal_rect& rect, float rx, float ry, const hal_color& clr, bool aa);

    protected:
        SkCanvas* raw_unsafe_canvas();

    protected:
        std::shared_ptr<hal_render_canvas> canvas_;
    };
}
#endif//Halberd_Kernal_Render_Al_Context_Hal_Render_Context_base_H_
