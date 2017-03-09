#include "hal_isolate.h"
using namespace kernal;

hal_isolate::hal_isolate() {

}

hal_isolate::~hal_isolate() {

}

bool hal_isolate::init() {
    if (!document_) {
        std::shared_ptr<hal_isolate> that_c = shared_from_this();
        document_ = hal_creator<hal_document>::instance(that_c);
        render_command_buffer_
            = hal_creator<hal_render_command_buffer>::instance(true);
    }
    return true;
}

std::shared_ptr<hal_document> hal_isolate::document() {
    return document_;
}
