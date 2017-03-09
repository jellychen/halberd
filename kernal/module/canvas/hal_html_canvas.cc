#include "hal_html_canvas.h"
using namespace kernal;

const char* hal_html_canvas::k_html_tag_name = "canvas";

bool hal_html_canvas::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    return true;
}
