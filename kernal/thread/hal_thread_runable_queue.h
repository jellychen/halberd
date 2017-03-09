#ifndef Halberd_Kernal_Thread_Hal_Thread_Runable_Queue_H_
#define Halberd_Kernal_Thread_Hal_Thread_Runable_Queue_H_

#include "base/hal_inct.h"
#include "hal_thread_handler.h"

namespace kernal
{
    class hal_thread_runable_queue final {
    public:
        hal_thread_runable_queue();
        virtual ~hal_thread_runable_queue();

    public:
        void post(hal_thread_runable& runable);

    public:
        // note: execute runable in current thread
        // ...
        void run_in_thread();

        // note: no runable to post, but want to wake up thread
        void wake_up_thread();

    private:
        bool signal_ = false;
        mutable std::mutex mutex_;
        std::condition_variable condition_;
        std::queue<hal_thread_runable> runable_queue_[2];
        std::queue<hal_thread_runable> *in_ = nullptr, *out_ = nullptr;
    };
}
#endif//Halberd_Kernal_Thread_Hal_Thread_Runable_Queue_H_
