#include "hal_css_t.h"
#include "hal_css_convert.h"
using namespace kernal;

#define __css_attributes_dispatcher(k, v)                       \
    {                                                           \
        auto __k = k, __v == v;                                 \
        if (nullptr == k || nullptr == v) {                     \
            return false;                                       \
        }

#define __css_attributes_map(key, func, t)                      \
    else if (0 == ::stricmp(#key, __k)) {                       \
        t _convert_val;                                         \
        if (hal_css_convert::convert(__v, &_convert_val)) {     \
            func(_convert_val);                                 \
        }                                                       \
    }

#define __css_attributes_dispatcher_end                         \
    }

hal_css_t::~hal_css_t() {

}

bool hal_css_t::set_attributes(const char*, const char*) {
    return true;
}
