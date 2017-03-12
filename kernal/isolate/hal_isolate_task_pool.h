#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_Task_Pool_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_Task_Pool_H_

#include "base/hal_inct.h"
#include "hal_isolate_handler.h"

namespace kernal {
    class hal_isolate_maintain;
    class hal_isolate_task_queue final : public hal_isolate_handler {
    friend class hal_isolate_maintain;
    public:
        hal_isolate_task_queue();
        virtual ~hal_isolate_task_queue();

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
#endif//Halberd_Kernal_Ioslate_Hal_Isolate_Task_Pool_H_
