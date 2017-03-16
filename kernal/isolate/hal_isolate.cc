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
    // note: create canvas
    auto render_canvas_size = hal_size_make(200, 200);
    render_canvas_
        = hal_creator<hal_render_mem_canvas>::instance(render_canvas_size);
    if (!render_canvas_) return false;

    // note: create context
    render_context_
        = hal_creator<hal_render_context>::instance(render_canvas_);
    if (!render_context_) return false;

    // note: create render command buffer
    render_command_buffer_
        = hal_creator<hal_render_command_buffer>::instance(true);
    if (!render_command_buffer_) return false;

    // note: create maintain
    isolate_maintain_
        = hal_creator<hal_isolate_maintain>::instance(render_command_buffer_);
    if (!isolate_maintain_) return false;

    // note: create raster thread
    raster_thread_
        = hal_creator<hal_render_raster_thread>::instance(
        render_context_, render_command_buffer_);
    if (!isolate_maintain_) return false;

    return true;
}

bool hal_isolate::resize_view(hal_size& size) {
    if (!isolate_maintain_) {
        return false;
    }

    hal_size new_size = size;
    isolate_maintain_->post([new_size](hal_isolate_maintain* maintain) {
        if (nullptr != maintain) {
            hal_size size = new_size;
            maintain->resize_document_view_size(size);
        }
    });
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

bool hal_isolate::capture_canvas_to_file(const char* name, bool current) {
    if (nullptr == name) return false;

    if (current) {
        if (!render_command_buffer_) return false;
        std::string std_name_str(name);
        std::function<void(std::shared_ptr<hal_render_context>&)> runable
            = [std_name_str] (std::shared_ptr<hal_render_context>& context) {
            if (context) context->capture_to_file(std_name_str.c_str());
        };
        std_name_str = ""; render_command_buffer_->commit(runable);
    } else {
        if (!isolate_maintain_) return false;
        std::string std_name_str(name);
        std::function<void(hal_isolate_maintain*)> runable
            = [std_name_str] (hal_isolate_maintain* maintain) {
            maintain->capture_canvas_to_file(std_name_str.c_str());
        };
        std_name_str = ""; isolate_maintain_->post(runable);
    }
    return true;

}
