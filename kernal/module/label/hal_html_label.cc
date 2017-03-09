#include "hal_html_label.h"
using namespace kernal;

const char* hal_html_label::k_html_tag_name = "label";

bool hal_html_label::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    return true;
}
