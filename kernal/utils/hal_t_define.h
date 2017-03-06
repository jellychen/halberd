#ifndef Halberd_Kernal_Utils_Hal_T_Define_H_
#define Halberd_Kernal_Utils_Hal_T_Define_H_

#include <base/hal_inct.h>

namespace kernal {
    struct hal_point {
        float x_, y_;
    };
    class hal_point_t: public hal_point {
    public:
        hal_point_t(float x =0, float y =0) {
            x_ = x; y_ = y;
        }
    };

    inline hal_point_t hal_point_make(float x, float y) {
        return hal_point_t(x, y);
    }

    struct hal_size {
        float width_, height_;
    };
    class hal_size_t: public hal_size {
    public:
        hal_size_t(float w =0, float h =0) {
            width_ = w; height_ = h;
        }
    };

    inline hal_size_t hal_size_make(float w, float h) {
        return hal_size_t(w, h);
    }

    struct hal_rect {
        float x_, y_, width_, height_;
    };
    class hal_rect_t: public hal_rect {
    public:
        hal_rect_t(float x =0, float y =0, float w =0, float h=0) {
            x_ = x; y_ = y; width_ = w; height_ = h;
        }
    };

    inline hal_rect_t hal_rect_make(float x, float y, float w, float h) {
        return hal_rect_t(x, y, w, h);
    }

    struct hal_divide {
        float left_, top_, right_, bottom_;
    };
    class hal_divide_t: public hal_divide {
    public:
        hal_divide_t(float l =0, float t =0, float r =0, float b =0) {
            left_ = l; top_ = t; right_ = r; bottom_ = b;
        }
    };

    inline hal_divide_t hal_divide_make(float l, float t, float r, float b) {
        return hal_divide_t(l, t, r, b);
    }

    struct hal_color {
        uint8_t r_, g_, b_, a_;
    };
    class hal_color_t: public hal_color {
    public:
        hal_color_t(uint8_t r =0, uint8_t g =0, uint8_t b =0, uint8_t a =0) {
            r_ = r; g_ = g; b_ = b; a_ = a;
        }
    };

    inline hal_color_t hal_color_make(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return hal_color_t(r, g, b, a);
    }
}
#endif//Halberd_Kernal_Utils_Hal_T_Define_H_
