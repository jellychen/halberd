#include <dom/hal_document.h>
#include <isolate/hal_isolate.h>

#include "hal_html_image.h"
using namespace kernal;

const char* hal_html_image::k_html_tag_name = "img";

bool hal_html_image::init_construct() {
    if (false == _parent::init_construct()) {
        return false;
    }
    auto command_buffer = _parent::render_command_buffer();
    texture_ = hal_creator<hal_render_command_texture>::instance(command_buffer);
    return (bool)texture_;
}

bool hal_html_image::set_image_url(const char* url) {
    return true;
}

bool hal_html_image::set_image_buffer(const char* buffer, uint32_t size) {
    return true;
}
