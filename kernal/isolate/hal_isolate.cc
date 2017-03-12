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

    // nore: create maintain
    isolate_maintain_
        = hal_creator<hal_isolate_maintain>::instance(render_command_buffer_);
    if (!isolate_maintain_) return false;

    return true;
}

bool hal_isolate::load_url(const char* url) {
    if (nullptr == url || !isolate_maintain_) {
        return false;
    }

    std::string std_url_str(url);
    std::function<void(hal_isolate_maintain*)> runable
        = [std_url_str] (hal_isolate_maintain* maintain) {
        maintain->load_url(std_url_str.c_str());
    };
    std_url_str = ""; isolate_maintain_->post(runable);
    return true;
}

bool hal_isolate::load_from_file(const char* name) {
    if (nullptr == name || !isolate_maintain_) {
        return false;
    }

    std::string std_name_str(name);
    std::function<void(hal_isolate_maintain*)> runable
        = [std_name_str] (hal_isolate_maintain* maintain) {
        maintain->load_url(std_name_str.c_str());
    };
    std_name_str = ""; isolate_maintain_->post(runable);
    return true;
}
