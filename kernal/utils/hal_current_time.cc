#include "hal_current_time.h"
using namespace kernal;

hal_current_time::hal_current_time() {
    hal_current_time::reset();
}

hal_current_time::~hal_current_time() {
}

void hal_current_time::reset() {
    begin_ = std::chrono::high_resolution_clock::now();
}

int64_t hal_current_time::elapsed() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - begin_).count();
}
