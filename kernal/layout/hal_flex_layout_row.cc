#include "hal_flex.h"
#include "component/hal_component.h"
using namespace kernal;

bool hal_flex::layout_row_wrap(
    std::shared_ptr<hal_component>& component, const hal_rect& rect) {

    hal_css_t& css = component->css_;
    float avaliable_width = rect.width_ - css.border_.left_
        - css.border_.right_ - css.padding_.left_ - css.padding_.right_;
    float avaliable_height = rect.height_ - css.border_.top_
        - css.border_.bottom_ - css.padding_.top_ - css.padding_.bottom_;

    int current_line_flex_total = 0;
    int current_line_flex_total_maybe = 0;
    int current_line_start_index = 0;
    int current_line_elements_count = 0;

    float current_line_top = css.padding_.top_;
    float current_line_use_width = 0;
    float current_line_flex_min_width = 0;
    float current_line_use_width_maybe = 0;
    float current_line_flex_min_width_maybe = 0;

    for (uint32_t index =0; index < component->children_count();) {
        auto child = std::dynamic_pointer_cast<hal_component>(component->at(index));
        if (!child) {
            ++index; continue;
        }

        hal_css_t& child_css = child->css_;

        // note: not visible
        if (hal_css_display_none == child_css.display_) {
            ++index; continue;
        }

        // note: absolute element
        if (hal_css_postion_absolute == child_css.position_) {
            hal_flex::layout_absolute(child, rect);
            ++index; continue;
        }

        // note: fixed element
        if (hal_css_postion_fixed == child_css.position_) {
            ++index; continue;
        }

        if (_is_css_val_valid(child_css.flex_grow_)) {
            current_line_flex_total_maybe += child_css.flex_grow_;
            current_line_flex_min_width_maybe += child_css.min_size_.width_;
            current_line_use_width_maybe += child_css.min_size_.width_
                + child_css.margin_.left_ + child_css.margin_.right_;
        } else {
            float width = 0;
            if (_is_css_val_valid(child_css.size_.width_)) {
                width = child_css.clamp_width();
            } else {
                hal_size calc_size = hal_size_make(0, 0);
                calc_size = child ->measure_size(calc_size, hal_layout_no_limited);
                width = calc_size.width_;
            }
            current_line_use_width_maybe += width + child_css.margin_.left_ + child_css.margin_.right_;
        }
    }
    return true;
}

bool hal_flex::layout_row_nowrap(
    std::shared_ptr<hal_component>& component, const hal_rect& rect) {
    return true;
}
