#include "hal_package_data.h"
using namespace kernal;

hal_package_data::hal_package_data() {
}

hal_package_data::~hal_package_data() {
}

void hal_package_data::clear() {
    inner_buffer_.clear();
}

void hal_package_data::resize(uint32_t size) {
    inner_buffer_.resize(size);
}

uint32_t hal_package_data::size() {
    return (uint32_t)(inner_buffer_.size());
}

uint8_t* hal_package_data::raw_buffer() {
    return (uint8_t*)(inner_buffer_.c_str());
}

bool hal_package_data::append_buffer(
    const uint8_t* buffer, uint32_t size) {
    if (nullptr == buffer || 0 == size) {
        return false;
    }
    inner_buffer_.append((const char*)buffer, size);
    return true;
}

bool hal_package_data::copy_from_raw_buffer(
    const uint8_t* buffer, uint32_t size) {
    if (nullptr == buffer || 0 == size) {
        inner_buffer_.clear();
    } else {
        inner_buffer_.resize(size);
        ::memcpy((void*)(inner_buffer_.c_str()), (void*)buffer, size);
    }
    return true;
}
