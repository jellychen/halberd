#include "hal_css_t.h"
#include "hal_css_define.h"
#include "hal_css_convert.h"
using namespace kernal;

#define __css_attributes_dispatcher(k, v)                       \
    {                                                           \
        auto __k = k, __v = v;                                  \
        if (nullptr == k || nullptr == v) {                     \
            return false;                                       \
        }

#define __css_attributes_map(key, func, t)                      \
    else if (0 == ::strcmp(#key, __k)) {                        \
        t _convert_val;                                         \
        if (hal_css_convert::convert(__v, &_convert_val)) {     \
            func(this, _convert_val);                           \
        }                                                       \
    }

#define __css_attributes_dispatcher_end()                       \
        return true;                                            \
    }


void internal_set_z_index(hal_css_t* that, int32_t v) {
    if (nullptr != that) {
        that->z_index_ = v;
    }
}

void internal_set_flex_grow(hal_css_t* that, float v) {
    if (nullptr != that) {
        that->flex_grow_ = v;
    }
}

hal_css_t::hal_css_t() {
    max_size_.width_  = k_hal_css_val_max;
    max_size_.height_ = k_hal_css_val_max;
}

bool hal_css_t::set_attributes(const char* k, const char* v) {
    __css_attributes_dispatcher(k, v)
    __css_attributes_map(zIndex, internal_set_z_index, int32_t)
    __css_attributes_map(z-index, internal_set_z_index, int32_t)
    __css_attributes_dispatcher_end()
    return true;
}
