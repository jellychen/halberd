#ifndef Halberd_Kernal_Utils_Hal_Min_Heap_Timer_Node_H_
#define Halberd_Kernal_Utils_Hal_Min_Heap_Timer_Node_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_min_heap_timer_node final {
    public:
        hal_min_heap_timer_node();

    public:
        bool is_circle_ = false;
        int64_t timeout_time_ = 0;
        int64_t interval_time_ = 0;
        std::function<void(uint32_t)> callback_;
        uint32_t t_id_ = 0, current_index_ = 0;
    };
}
#endif//Halberd_Kernal_Utils_Hal_Min_Heap_Timer_Node_H_
