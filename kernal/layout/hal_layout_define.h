#ifndef Halberd_Kernal_Layout_Hal_Layout_Define_H_
#define Halberd_Kernal_Layout_Hal_Layout_Define_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"

namespace kernal {

    class hal_flex_layout_size {
    public:
        // note: if limit maybe width or height
        // note: if < 0 is no limit
        float limit_ = 0;

        // note: is have measure size
        bool measured_ = false;

        // note: is measure size;
        hal_size measure_size_;
    };
}
#endif//Halberd_Kernal_Layout_Hal_Layout_Define_H_
