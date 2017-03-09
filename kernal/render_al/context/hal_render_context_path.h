#ifndef Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Path_H_
#define Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Path_H_

#include "hal_render_context_clip.h"

namespace kernal {
    class hal_render_context_path
        : public hal_render_context_clip {
    public:
        using _parent = hal_render_context_clip;
        using hal_render_context_clip::hal_render_context_clip;

    public:
        // note: clear current path
        void clear_path();

    public:
        // note: this function will be clear last path
        void begin_path();

        // note: this function will close current path
        void close_path();

        // note: path create
        void move_to(const hal_point& pt);
        void line_to(const hal_point& pt);
        void quad_to(const hal_point& pt0, const hal_point& pt1);
        void cubi_to(const hal_point& pt0, const hal_point& pt1, const hal_point& pt2);

    public:
        // note: render raster
        bool fill_path(const hal_color& clr, bool aa);
        bool stroke_path(const hal_color& clr, bool width, bool aa);
        bool stroke_fill_path(const hal_color& clr, bool width, bool aa);

    protected:
        SkPath path_;
    };
}
#endif//Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Path_H_
