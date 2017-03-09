#include "hal_thread_runable_queue.h"
using namespace kernal;

hal_thread_runable_queue::hal_thread_runable_queue()
    :in_(runable_queue_), out_(runable_queue_+1) {
        printf("\n\n\n");
}

hal_thread_runable_queue::~hal_thread_runable_queue() { printf("%s\n", "~hal_thread_runable_queue");
}

void hal_thread_runable_queue::post(hal_thread_runable& runable) {

    if (!runable) {
        return;
    }
    printf("%d\n", __LINE__);
    std::unique_lock<std::mutex> lock(mutex_);
    printf("%d\n", __LINE__);
    in_->push(runable); signal_ = true; lock.unlock();
    condition_.notify_one();
}

void hal_thread_runable_queue::run_in_thread() {
    printf("%s\n", "run_in_thread 0");
    std::unique_lock<std::mutex> lock(mutex_);
    printf("%s\n", "run_in_thread 1");
    condition_.wait(lock, [this]{ return this->signal_; });
    signal_ = false; std::swap(in_, out_); printf("%s\n", "run_in_thread 2");
    lock.unlock();

    while (out_->size() > 0) {
        out_->front()(); out_->pop();
    }
}

void hal_thread_runable_queue::wake_up_thread() {
    printf("%d\n", __LINE__);
    std::unique_lock<std::mutex> lock(mutex_);
    printf("%d\n", __LINE__);
    signal_ = true; lock.unlock();
    printf("%s\n", "wake_up_thread 1");
    condition_.notify_one();
    printf("%s\n", "wake_up_thread 2");
}
