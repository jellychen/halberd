#include "hal_thread_instance.h"
using namespace kernal;

static void hal_thread_main(hal_thread_instance* thread) {
    if (nullptr == thread) {
        return;
    }
    while (false == thread->should_exit_) {
        thread->runable_queue_.run_in_thread();
    }
}

hal_thread_instance::hal_thread_instance():thread_(hal_thread_main, this) {

}

hal_thread_instance::~hal_thread_instance() {
    should_exit_ = true;
    runable_queue_.wake_up_thread();
    thread_.join();
}

void hal_thread_instance::post(hal_thread_runable& runable) {
    runable_queue_.post(runable);
}
