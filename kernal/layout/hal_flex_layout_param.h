#ifndef Halberd_Kernal_Layout_Hal_Flex_Layout_Param_H_
#define Halberd_Kernal_Layout_Hal_Flex_Layout_Param_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_component_layout;

    class hal_flex_layout_param final {
    public:
        // note: container size
        hal_size size_;

        // note: document view size
        hal_size view_port_size_;

        // note:
        hal_rect relative_rect_;

        // note: visible rect
        hal_rect visible_rect_;
    };
}
#endif//Halberd_Kernal_Layout_Hal_Flex_Layout_Param_H_
