#include "hal_thread_runable_queue.h"
using namespace kernal;

hal_thread_runable_queue::hal_thread_runable_queue()
    :in_(runable_queue_), out_(runable_queue_+1) {
}

hal_thread_runable_queue::~hal_thread_runable_queue() {
}

void hal_thread_runable_queue::post(hal_thread_runable& runable) {
    if (!runable) {
        return;
    }

    if (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        in_->push(runable); signal_ = true;
    }
    condition_.notify_one();
}

void hal_thread_runable_queue::run_in_thread() {
    if (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this]{return signal_;});
        signal_ = false; std::swap(in_, out_);
    }

    while (out_->size() > 0) {
        out_->front()(); out_->pop();
    }
}

void hal_thread_runable_queue::wake_up_thread() {
    if (true){
        std::unique_lock<std::mutex> lock(mutex_);
        signal_ = true;
    }
    condition_.notify_one();
}
