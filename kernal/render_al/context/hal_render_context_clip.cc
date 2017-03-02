#define SK_SUPPORT_EXOTIC_CLIPOPS

#include "hal_render_context_clip.h"
using namespace kernal;

bool hal_render_context_clip::clip_union(const hal_rect& rect, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    
    canvas->clipRect(__convert_to_t(rect), SkClipOp::kUnion, aa);
    return true;
}

bool hal_render_context_clip::clip_replace(const hal_rect& rect, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    canvas->clipRect(__convert_to_t(rect), SkClipOp::kReplace, aa);
    return true;
}

bool hal_render_context_clip::clip_intersect(const hal_rect& rect, bool aa) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    canvas->clipRect(__convert_to_t(rect), SkClipOp::kIntersect, aa);
    return true;
}
