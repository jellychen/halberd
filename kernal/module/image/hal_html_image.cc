#include "hal_html_image.h"
using namespace kernal;

const char* hal_html_image::k_html_tag_name = "img";

bool hal_html_image::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    return true;
}
