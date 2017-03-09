#include "isolate/hal_isolate.h"
#include "hal_document.h"
using namespace kernal;

hal_document::hal_document() {
}

hal_document::hal_document(std::shared_ptr<hal_isolate>& isolate) {
    host_isolate_ = isolate;
}

hal_document::~hal_document() {
}

std::shared_ptr<hal_isolate> hal_document::host_isolate() {
    return host_isolate_.lock();
}
