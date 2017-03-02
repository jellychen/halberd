#include "hal_flex.h"
using namespace kernal;

bool hal_flex::layout_row_wrap(
    std::shared_ptr<hal_component>&, const hal_rect&) {
        /*
        hal_css_t& css = component->css_;
        float avaliable_width = rect.width_ - css.border_.left_
            - css.border_.right_ - css.padding_.left_ - css.padding_.right_;
        float avaliable_height = rect.height_ - css.border_.top_
            - css.border_.bottom_ - css.padding_.top_ - css.padding_.bottom_;
        */
    return true;
}

bool hal_flex::layout_row_nowrap(
    std::shared_ptr<hal_component>&, const hal_rect&) {
    return true;
}
