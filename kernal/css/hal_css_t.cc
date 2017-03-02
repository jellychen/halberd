#include "hal_css_t.h"
#include "hal_css_convert.h"
using namespace kernal;

hal_css_t::hal_css_t() {
    size_.width_ = k_hal_css_val_nan;
    size_.height_ = k_hal_css_val_nan;
    max_size_.width_ = k_hal_css_val_max;
    max_size_.height_ = k_hal_css_val_max;
}

float hal_css_t::clamp_width() const {
    float width = size_.width_;
    if (width < min_size_.width_) {
        width = min_size_.width_;
    }
    if (width > max_size_.width_) {
        width = max_size_.width_;
    }
    return width;
}

float hal_css_t::clamp_height() const {
    float height = size_.height_;
    if (height < min_size_.height_) {
        height = min_size_.height_;
    }
    if (height > max_size_.height_) {
        height = max_size_.height_;
    }
    return height;
}
