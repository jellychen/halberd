#include "hal_flex.h"
using namespace kernal;

hal_flex::hal_flex() {
}

hal_flex::hal_flex(
    std::shared_ptr<hal_component>& component)
    : host_component_(component) {
}

hal_flex::~hal_flex() {
}

bool hal_flex::attach_component(
    std::shared_ptr<hal_component>& component) {
    host_component_ = component;
    return true;
}
