#include "dom/hal_document.h"
#include "hal_component_layout.h"
using namespace kernal;

bool hal_component_layout::init_construct() {
    flex_layout_.attach_component(
        std::dynamic_pointer_cast<hal_component_layout>(shared_from_this()));
    return true;
}

hal_size hal_component_layout::measure_size(
    hal_size&, hal_layout_type) {
    return hal_size_make(0, 0);
}

void hal_component_layout::layout_children(
    const hal_rect&, const hal_rect&) {

}

hal_rect hal_component_layout::rect() const {
    return hal_rect_make(0,0,0,0);
}

hal_rect hal_component_layout::document_relative_rect() const {
    return hal_rect_make(0,0,0,0);
}

void hal_component_layout::invalidate_layout() {

}

void hal_component_layout::internal_set_layouted() {

}
