#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_isolate_maintain;
    class hal_isolate_handler final {
    friend class hal_isolate_maintain;
    public:
        hal_isolate_handler();
        virtual ~hal_isolate_handler();

    public:
        void post(std::function<void(hal_isolate_maintain*)>&);

    private:
        void weak_up_thread();
        void wait_and_run_runable(hal_isolate_maintain*);
        void wait_and_run_runable_util(hal_isolate_maintain*, uint32_t);

    private:
        bool signal_ = false;
        mutable std::mutex mutex_;
        std::condition_variable condition_;
        std::queue<std::function<void(hal_isolate_maintain*)>> runable_queue_;
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_
