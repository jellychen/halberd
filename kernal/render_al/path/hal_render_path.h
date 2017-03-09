#ifndef Halberd_Kernal_Render_Al_Path_Hal_Render_Path_H_
#define Halberd_Kernal_Render_Al_Path_Hal_Render_Path_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "render_al/hal_render_require.h"
#include "render_al/context/hal_render_context.h"

namespace kernal {
    class hal_render_path final {
    public:
        hal_render_path();
        virtual ~hal_render_path();

    public:
        void clear();

    public:
        void move_to(const hal_point& pt);
        void line_to(const hal_point& pt);
        void quad_to(const hal_point& pt0, const hal_point& pt1);
        void cubi_to(const hal_point& pt0, const hal_point& pt1, const hal_point& pt2);

        void close();

    public:
        bool fill(std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool aa);
        bool stroke(std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool width, bool aa);
        bool stroke_fill(std::shared_ptr<hal_render_context>& context, const hal_color& clr, bool width, bool aa);

    public:
        bool clip_union(std::shared_ptr<hal_render_context>& context, bool aa);
        bool clip_replace(std::shared_ptr<hal_render_context>& context, bool aa);
        bool clip_intersect(std::shared_ptr<hal_render_context>& context, bool aa);

    private:
        SkPath path_;
    };
}
#endif//Halberd_Kernal_Render_Al_Path_Hal_Render_Path_H_
