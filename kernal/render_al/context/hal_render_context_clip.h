#ifndef Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Clip_H_
#define Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Clip_H_

#include "hal_render_context_base.h"

namespace kernal {
    class hal_render_context_clip
        : public hal_render_context_base {
    public:
        using _parent = hal_render_context_base;
        using hal_render_context_base::hal_render_context_base;

    public:
        bool clip_union(const hal_rect rect, bool aa);
        bool clip_replace(const hal_rect rect, bool aa);
        bool clip_intersect(const hal_rect rect, bool aa);
    };
}
#endif//Halberd_Kernal_Render_Al_Context_Hal_Render_Context_Clip_H_
