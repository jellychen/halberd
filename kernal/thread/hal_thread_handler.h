#ifndef Halberd_Kernal_Thread_Hal_Thread_Handler_H_
#define Halberd_Kernal_Thread_Hal_Thread_Handler_H_

#include "base/hal_inct.h"

namespace kernal
{
    using hal_thread_runable = std::function<void()>;

    class hal_thread_handler {
    public:
        virtual ~hal_thread_handler() {}

    public:
        virtual void post(hal_thread_runable& runable) =0;
    };
}
#endif//Halberd_Kernal_Thread_Hal_Thread_Handler_H_
