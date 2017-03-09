#ifndef Halberd_Kernal_Thread_Hal_Thread_Instance_H_
#define Halberd_Kernal_Thread_Hal_Thread_Instance_H_

#include "base/hal_inct.h"
#include "hal_thread_handler.h"
#include "hal_thread_runable_queue.h"

namespace kernal
{
    class hal_thread_instance final
        : public hal_thread_handler {
    public:
        hal_thread_instance();
        virtual ~hal_thread_instance();

    public:
        void post(hal_thread_runable& runable);

    public:
        std::thread thread_;
        std::atomic_bool should_exit_ = {false};
        hal_thread_runable_queue runable_queue_;
    };
}
#endif//Halberd_Kernal_Thread_Hal_Thread_Instance_H_
