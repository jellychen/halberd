#include <css/hal_css_parser.h>

#include "hal_document.h"
#include "hal_component.h"
using namespace kernal;

__hal_attributes_define(hal_component);
__hal_attributes_map(style, internal_attr_set_style);
__hal_attributes_define_end();

bool hal_component::set_attributes(const char* k, const char* val) {
    std::string _attr_k = k;
    return __hal_attributes_dispatch(hal_component).dispath(_attr_k, val, this);
}

bool hal_component::set_style_attributes(const char* k, const char* val) {
    return css_.set_attributes(k, val);
}

void hal_component::internal_attr_set_style(const char* str) {
    if (nullptr != str) {
        auto component = std::dynamic_pointer_cast<hal_component>(shared_from_this());
        if (component) {
            hal_css_parser parser;
            parser.declaration_list(str, strlen(str), component);
        }
    }
}
