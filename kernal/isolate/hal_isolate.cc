#include "hal_isolate.h"
using namespace kernal;

hal_isolate::hal_isolate() {
}

hal_isolate::~hal_isolate() {
    // note: stop raster thread
    if (raster_thread_) {
        raster_thread_->stop_and_wait();
    }
}

bool hal_isolate::init() {
    // note: create render command buffer
    render_command_buffer_
        = hal_creator<hal_render_command_buffer>::instance(true);
    if (!render_command_buffer_) return false;

    // note: create document
    document_ = hal_creator<hal_document>::instance(render_command_buffer_);
    if (!document_) return false;

    return true;
}
