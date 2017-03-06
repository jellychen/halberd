#ifndef Halberd_Kernal_Layout_Hal_Layout_H_
#define Halberd_Kernal_Layout_Hal_Layout_H_

#include <base/hal_inct.h>

#include "hal_flex.h"
#include "hal_foundation.h"

namespace kernal {
    class hal_layout final {
    public:
        hal_layout();
        virtual ~hal_layout();

    public:
        union {
            hal_flex flex_layout_;
            hal_foundation foundation_layout_;
        };
    };
}
#endif//Halberd_Kernal_Layout_Hal_Layout_H_
