#include "hal_flex.h"
#include "component/hal_component.h"
using namespace kernal;

bool hal_flex::layout(
    const hal_size& size, const hal_rect& rrect, const hal_rect& vrect) {
    if (!host_component_.expired()) {
        auto component = host_component_.lock();

        hal_flex_layout_param layout_param;
        layout_param.visible_rect_ = vrect;
        layout_param.relative_rect_ = rrect;
        layout_param.view_port_size_ = size;
        layout_param.size_ = hal_size_make(
            component->rect_.width_, component->rect_.height_);

        measure_cache_.resize(component->children_count());
        if (hal_css_flex_row == component->css_.flex_direction_) {
            return hal_flex::layout_row(layout_param);
        } else if (hal_css_flex_column == component->css_.flex_direction_) {
            return hal_flex::layout_cloumn(layout_param);
        }
        measure_cache_.clear();
    }
    return false;
}

bool hal_flex::layout_row(const hal_flex_layout_param& param) {
    if (!host_component_.expired()) {
        if (hal_css_flex_wrap == host_component_.lock()->css_.flex_wrap_) {
            return hal_flex::layout_row(param);
        } else {
            return hal_flex::layout_row_nowrap(param);
        }
    }
    return false;
}

bool hal_flex::layout_cloumn(const hal_flex_layout_param& param) {
    if (!host_component_.expired()) {
        if (hal_css_flex_wrap == host_component_.lock()->css_.flex_wrap_) {
            return hal_flex::layout_row(param);
        } else {
            return hal_flex::layout_row_nowrap(param);
        }
    }
    return false;
}
