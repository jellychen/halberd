#include "hal_document.h"
#include "hal_component.h"
using namespace kernal;

void hal_component::layout_children(const hal_rect&, bool) {
    return ;
}

hal_size hal_component::measure_size(const hal_size&, hal_measure_style) {
    return hal_size_make(0, 0);
}
