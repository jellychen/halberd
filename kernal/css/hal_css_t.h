#ifndef Halberd_Kernal_Css_Hal_Css_T_H_
#define Halberd_Kernal_Css_Hal_Css_T_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "hal_css_enum.h"
#include "hal_css_define.h"

namespace kernal {
    class hal_css_t final {
    public:
        hal_css_t();

    public:
        bool set_attributes(const char*, const char*);

    public:
        // note: zindex
        int32_t z_index_ = 0;

        // note: flex grow
        float flex_grow_ = k_hal_css_val_nan;

        // note: max size; min size; size
        hal_size_t size_, max_size_, min_size_;

        // note: css box model
        hal_divide_t margin_, padding_, border_;

        // note: location divide
        // note: left, top, right, bottom
        hal_divide_t location_divide_;

        // note: display
        hal_css_display_t display_ = hal_css_display_auto;

        // note: position
        // note: absolute, fixed, relative
        hal_css_postion_t position_ = hal_css_postion_auto;

        // note: flex direction
        hal_css_flex_direction_t flex_direction_ = hal_css_flex_direction_auto;

        // note: flex wrap
        hal_css_flex_wrap_t flex_wrap_ = hal_css_flex_wrap_auto;

        // note: flex align self
        hal_css_flex_align_t flex_align_self = hal_css_flex_none;

        // note: flex
        hal_css_flex_align_t flex_justify_content = hal_css_flex_align_auto;

    public:
        // note: clamp
        float clamp_width() const;

        // note: clamp
        float clamp_height() const;

        // note: clamp value
        float clamp_width(float width) const;

        // note: clamp value
        float clamp_height(float height) const;
    };
}
#endif//Halberd_Kernal_Css_Hal_Css_T_H_
