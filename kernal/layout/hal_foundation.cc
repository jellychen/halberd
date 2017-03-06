#include "hal_foundation.h"
using namespace kernal;

hal_foundation::hal_foundation() {

}

hal_foundation::~hal_foundation() {

}

bool hal_foundation::measure() {
    return true;
}

bool hal_foundation::layout(
    std::shared_ptr<hal_component>& component, const hal_rect& rect) {
    return true;
}
