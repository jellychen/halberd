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

void hal_component_layout::layout_children(const hal_rect& vrect) {
    //flex_layout_.layout(rect_, document_relative_rect_, vrect);
}

hal_rect hal_component_layout::rect() const {
    return hal_rect_make(0,0,0,0);
}

hal_rect hal_component_layout::document_relative_rect() const {
    return hal_rect_make(0,0,0,0);
}

bool hal_component_layout::sync_document_area_index(bool deep) {
    if (false == is_sync_area_index_ && !host_document_.expired()) {
        auto component = std::dynamic_pointer_cast<hal_component_layout>(shared_from_this());
        if (component) {
            host_document_.lock()->area_index_.add(visible_rect_, component);
        }
        is_sync_area_index_ = true;
    }

    for (size_t i =0; i < children_.size(); ++i) {
        std::shared_ptr<hal_element>& ele = children_[i];
        auto component = std::dynamic_pointer_cast<hal_component_layout>(ele);
        if (component) {
            component->sync_document_area_index(deep);
        }
    }
    return true;
}

void hal_component_layout::invalidate_layout() {

}

void hal_component_layout::internal_set_layouted() {

}
