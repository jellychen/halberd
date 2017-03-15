#include "hal_flex.h"
#include "component/hal_component.h"
using namespace kernal;

bool hal_flex::layout(
    const hal_rect& rect, const hal_point& pt, const hal_rect& vrect) {
    document_relative_point_ = pt; current_visible_rect = vrect;
    if (!host_component_.expired()) {
        auto component = host_component_.lock();
        measure_cache_.resize(component->children_count());
        if (hal_css_flex_row == component->css_.flex_direction_) {
            return hal_flex::layout_row(component, rect);
        } else if (hal_css_flex_column == component->css_.flex_direction_) {
            return hal_flex::layout_cloumn(component, rect);
        }
        measure_cache_.clear();
    }
    return false;
}

bool hal_flex::layout_row(
    std::shared_ptr<hal_component_layout>& component, const hal_rect& rect) {
    if (component) {
        if (hal_css_flex_wrap == component->css_.flex_wrap_) {
            return hal_flex::layout_row(component, rect);
        } else {
            return hal_flex::layout_row_nowrap(component, rect);
        }
    }
    return false;
}

bool hal_flex::layout_cloumn(
    std::shared_ptr<hal_component_layout>& component, const hal_rect& rect) {
    if (component) {
        if (hal_css_flex_wrap == component->css_.flex_wrap_) {
            return hal_flex::layout_row(component, rect);
        } else {
            return hal_flex::layout_row_nowrap(component, rect);
        }
    }
    return false;
}
