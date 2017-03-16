#include "hal_render_raster_thread.h"
using namespace kernal;

hal_render_raster_thread::hal_render_raster_thread(
    std::shared_ptr<hal_render_context>& render_context,
    std::shared_ptr<hal_render_command_buffer>& command_buffer)
    :render_context_(render_context), command_buffer_(command_buffer) {
    thread_ = std::thread([this] {
        printf("%s\n", "hal_render_raster_thread::hal_render_raster_thread");
        while (false == should_exit_ && command_buffer_ && render_context_) {
            command_buffer_->run_in_thread(render_context_);
        }
    });
}

hal_render_raster_thread::~hal_render_raster_thread() {
    if (false == should_exit_) {
        hal_render_raster_thread::stop_and_wait();
    }
}

bool hal_render_raster_thread::stop_and_wait() {
    should_exit_ = true;
    if (command_buffer_) {
        command_buffer_->wake_up_thread();
    }
    thread_.join();
    return true;
}
