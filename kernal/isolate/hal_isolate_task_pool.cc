#include "hal_isolate_task_pool.h"
using namespace kernal;

hal_isolate_task_queue::hal_isolate_task_queue() {
}

hal_isolate_task_queue::~hal_isolate_task_queue() {
}

void hal_isolate_task_queue::post(
    std::function<void(hal_isolate_maintain*)>& runable) {
    if (!runable) {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);
    runable_queue_.push(runable);
    signal_ = true;
    condition_.notify_one();
}

void hal_isolate_task_queue::weak_up_thread() {
    std::lock_guard<std::mutex> lock(mutex_);
    signal_ = true;
    condition_.notify_one();
}

void hal_isolate_task_queue::wait_and_run_runable(
    hal_isolate_maintain* isolate_maintain) {
    if (nullptr == isolate_maintain) {
        return;
    }

    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this]{return this->signal_;});
    signal_ = false;
    while (0 < runable_queue_.size()) {
        runable_queue_.front()(isolate_maintain);
        runable_queue_.pop();
    }
}

void hal_isolate_task_queue::wait_and_run_runable_util(
    hal_isolate_maintain* isolate_maintain, uint32_t timeout) {
    if (nullptr == isolate_maintain) {
        return;
    }
    //std::unique_lock<std::mutex> lock(mutex_);
}
