#include "hal_html_input.h"
using namespace kernal;

const char* hal_html_input::k_html_tag_name = "input";

bool hal_html_input::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    return true;
}
