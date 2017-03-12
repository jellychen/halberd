#include "hal_thread_instance.h"
using namespace kernal;

hal_thread_instance::hal_thread_instance() {
    thread_ = std::thread([this] {
        this->internal_thread_main();
    });
}

hal_thread_instance::~hal_thread_instance() {
    should_exit_ = true;
    runable_queue_.wake_up_thread();
    thread_.join();
}

void hal_thread_instance::post(
    hal_thread_runable& runable) {
    runable_queue_.post(runable);
}

void hal_thread_instance::internal_thread_main() {
    while (false == should_exit_) {
        runable_queue_.run_in_thread();
    }
}
