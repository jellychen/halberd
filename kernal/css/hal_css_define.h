#ifndef Halberd_Kernal_Css_Hal_Css_Define_H_
#define Halberd_Kernal_Css_Hal_Css_Define_H_

#include <base/hal_inct.h>

namespace kernal {
    const float k_hal_css_val_nan = std::numeric_limits<float>::max();
    const float k_hal_css_val_max = std::numeric_limits<float>::max() -1;

    inline bool _is_css_val_valid(float& val) {
        return val <= k_hal_css_val_max;
    }
}
#endif//Halberd_Kernal_Css_Hal_Css_Define_H_
