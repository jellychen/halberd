#include "hal_css_t.h"
#include "hal_css_convert.h"
using namespace kernal;

hal_css_t::hal_css_t() {
    size_.width_ = k_hal_css_val_nan;
    size_.height_ = k_hal_css_val_nan;
    max_size_.width_ = k_hal_css_val_max;
    max_size_.height_ = k_hal_css_val_max;
}

inline float __clamp_value(
    float v, float _min, float _max) {
    if (v < _min) { v = _min; }
    if (v > _max) { v = _max; }
    return v;
}

float hal_css_t::clamp_width() const {
    return __clamp_value(size_.width_,
        min_size_.width_, max_size_.width_);
}

float hal_css_t::clamp_height() const {
    return __clamp_value(size_.height_,
        min_size_.height_, max_size_.height_);
}

float hal_css_t::clamp_width(float width) const {
    return __clamp_value(width,
        min_size_.width_, max_size_.width_);
}

float hal_css_t::clamp_height(float height) const {
    return __clamp_value(height,
        min_size_.height_, max_size_.height_);
}
