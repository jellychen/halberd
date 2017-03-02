#ifndef Halberd_Kernal_Css_Hal_Css_T_H_
#define Halberd_Kernal_Css_Hal_Css_T_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>

#include "hal_css_enum.h"

namespace kernal
{
    class hal_css_t final {
    public:
        hal_css_t();

    public:
        bool set_attributes(const char*, const char*);

    public:
        // note: zindex
        int32_t z_index_ = 0;

        // note: flex grow
        float flex_grow_ = 0;

        // note: max size; min size; size
        hal_size_t size_, max_size_, min_size_;

        // note: css box model
        hal_divide_t margin_, padding_, border_;

        // note: location divide
        // note: left, top, right, bottom
        hal_divide_t location_divide_;

        // note: position
        // note: absolute, fixed, relative
        hal_css_postion_t position_ = hal_css_postion_auto;

        // note: flex direction
        hal_css_flex_direction_t flex_direction_ = hal_css_flex_direction_auto;

        // note: flex wrap
        hal_css_flex_wrap_t flex_wrap_ = hal_css_flex_wrap_auto;
    };
}
#endif//Halberd_Kernal_Css_Hal_Css_T_H_
