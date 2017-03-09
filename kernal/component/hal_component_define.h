#ifndef Halberd_Kernal_Dom_Hal_Component_Define_H_
#define Halberd_Kernal_Dom_Hal_Component_Define_H_

#include <base/hal_inct.h>

namespace kernal {
    
    enum hal_layout_type {
        hal_layout_no_limited           = 0x01,
        hal_layout_assgin_width         = 0x02,
        hal_layout_assgin_height        = 0x04,
        hal_layout_no_limited_width     = 0x08,
        hal_layout_no_limited_height    = 0x0a,
    };
}
#endif//Halberd_Kernal_Dom_Hal_Component_Define_H_
