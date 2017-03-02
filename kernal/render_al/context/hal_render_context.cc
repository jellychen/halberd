#include "hal_render_context.h"
using namespace kernal;

bool hal_render_context::rotate(float d) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->rotate(d); return true;
}

bool hal_render_context::skew(float x, float y) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->skew(x, y); return true;
}

bool hal_render_context::scale(float x, float y) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->scale(x, y); return true;
}

bool hal_render_context::translate(float x, float y) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->translate(x, y); return true;
}

bool hal_render_context::camera_rotate(float x, float y, float z) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    Sk3DView _3d_view;
    0 != x? _3d_view.rotateX(x): (void)0;
    0 != y? _3d_view.rotateY(y): (void)0;
    0 != z? _3d_view.rotateZ(z): (void)0;

    SkMatrix _3d_martix;
    _3d_view.getMatrix(&_3d_martix);
    canvas->concat(_3d_martix);

    return true;
}

bool hal_render_context::camera_translate(float x, float y, float z) {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }

    Sk3DView _3d_view;
    _3d_view.translate(x, y, z);

    SkMatrix _3d_martix;
    _3d_view.getMatrix(&_3d_martix);
    canvas->concat(_3d_martix);

    return true;
}

bool hal_render_context::save_state() {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->save(); return true;
}

bool hal_render_context::restore_state() {
    auto canvas = hal_render_context_base::raw_unsafe_canvas();
    if (nullptr == canvas) {
        return false;
    }
    canvas->restore(); return true;
}
