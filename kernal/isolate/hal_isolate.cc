#include "hal_isolate.h"
using namespace kernal;

hal_isolate::hal_isolate() {
}

hal_isolate::~hal_isolate() {
    // note: stop raster thread
    if (render_raster_thread_) {
        render_raster_thread_->stop_and_wait();
    }
}

bool hal_isolate::init() {
    if (!document_) {
        // note: create document
        std::shared_ptr<hal_isolate> that_c = shared_from_this();
        document_ = hal_creator<hal_document>::instance(that_c);
        if (!document_) return false;

        // note: create render command buffer
        render_command_buffer_
            = hal_creator<hal_render_command_buffer>::instance(true);
        if (!render_command_buffer_) return false;

        // note:
    }
    return true;
}

std::shared_ptr<hal_document> hal_isolate::document() {
    return document_;
}

std::shared_ptr<hal_render_command_buffer> hal_isolate::render_command_buffer() {
    return render_command_buffer_;
}
