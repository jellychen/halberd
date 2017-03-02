#include "hal_html_div.h"
using namespace kernal;

const char* hal_html_div::k_html_tag_name = "div";

bool hal_html_div::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    return true;
}
