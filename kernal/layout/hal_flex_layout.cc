#include "hal_flex.h"
using namespace kernal;

bool hal_flex::layout(std::shared_ptr<hal_component>& component, const hal_rect&) {
    if (!component) {
        return false;
    }
    return true;
}

bool hal_flex::layout_absolute(std::shared_ptr<hal_component>&, const hal_rect&) {
    return true;
}
