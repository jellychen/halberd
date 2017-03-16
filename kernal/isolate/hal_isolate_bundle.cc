#include "hal_isolate.h"
#include "hal_isolate_bundle.h"
using namespace kernal;

hal_isolate_bundle::hal_isolate_bundle() {
    isolate_kernal_ = hal_creator<hal_isolate>::instance();
    if (isolate_kernal_) {
        isolate_kernal_->init();
    }
}

hal_isolate_bundle::~hal_isolate_bundle() {
}

bool hal_isolate_bundle::resize_view(hal_size& size) {
    if (!isolate_kernal_) {
        return false;
    }
    return isolate_kernal_->resize_view(size);
}

bool hal_isolate_bundle::load_url(const char* url) {
    if (!isolate_kernal_) {
        return false;
    }
    return isolate_kernal_->load_url(url);
}

bool hal_isolate_bundle::load_from_file(const char* name) {
    if (!isolate_kernal_) {
        return false;
    }
    return isolate_kernal_->load_from_file(name);
}

bool hal_isolate_bundle::capture_canvas_to_file(const char* name) {
    if (!isolate_kernal_) {
        return false;
    }
    return isolate_kernal_->capture_canvas_to_file(name);
}
