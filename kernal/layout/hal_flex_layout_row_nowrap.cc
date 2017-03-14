#include "hal_flex.h"
#include "component/hal_component.h"
using namespace kernal;

bool hal_flex::layout_row_nowrap(
    std::shared_ptr<hal_component>& component, const hal_rect& rect) {
    return true;
}
