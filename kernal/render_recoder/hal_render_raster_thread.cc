#include "hal_render_raster_thread.h"
using namespace kernal;

static void hal_thread_main(hal_render_raster_thread* thread) {
    if (nullptr != thread) {
        thread->internal_thread_main();
    }
}

hal_render_raster_thread::hal_render_raster_thread(
    std::shared_ptr<hal_render_context>& render_context,
    std::shared_ptr<hal_render_command_buffer>& command_buffer)
    :render_context_(render_context), command_buffer_(command_buffer) {
    thread_ = std::thread(hal_thread_main, this);
}

hal_render_raster_thread::~hal_render_raster_thread() {
}

bool hal_render_raster_thread::stop_and_wait() {
    if (command_buffer_) {
        command_buffer_->wake_up_thread();
    }
    should_exit_ = true; thread_.join();
    return true;
}

void hal_render_raster_thread::internal_thread_main() {
    while (false == should_exit_ && command_buffer_ && render_context_) {
        command_buffer_->run_in_thread(render_context_);
    }
}
