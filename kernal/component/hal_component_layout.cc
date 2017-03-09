#include "dom/hal_document.h"
#include "hal_component.h"
using namespace kernal;

void hal_component::layout_children(const hal_rect&, bool) {
    return ;
}

hal_size hal_component::measure_size(hal_size&, hal_layout_type) {
    return hal_size_make(0, 0);
}

void hal_component::invalidate_layout() {

}
