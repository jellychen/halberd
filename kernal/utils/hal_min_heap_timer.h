#ifndef Halberd_Kernal_Utils_Hal_Min_Heap_Timer_H_
#define Halberd_Kernal_Utils_Hal_Min_Heap_Timer_H_

#include "base/hal_inct.h"
#include "hal_current_time.h"
#include "hal_min_heap_timer_node.h"

namespace kernal {
    class hal_min_heap_timer final {
    public:
        hal_min_heap_timer();
        virtual ~hal_min_heap_timer();

    public:
        // note: get last timeout time
        int64_t last_timeout() const;

        // note: do timeout function
        void tick();

    public:
        // note: erase timer
        bool erase(uint32_t);

        // note: add new timer
        bool add_timer(uint32_t, bool,
            std::function<void(uint32_t)>, uint32_t*);

    private:
        // note: adjust min heap
        void erase_adjust_min_heap(size_t index);
        void append_adjust_min_heap(size_t index);

    private:
        uint32_t current_id_ = 0;
        uint32_t min_heap_count_ = 1; hal_current_time current_time_;
        std::vector<std::shared_ptr<hal_min_heap_timer_node>> min_heap_;
        std::map<uint32_t, std::shared_ptr<hal_min_heap_timer_node>> t_id_index_;
    };
}
#endif//Halberd_Kernal_Utils_Hal_Min_Heap_Timer_H_
