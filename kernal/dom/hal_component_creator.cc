#include <module/div/hal_html_div.h>
#include <module/image/hal_html_image.h>
#include <module/label/hal_html_label.h>
#include <module/input/hal_html_input.h>
#include "hal_component_creator.h"
using namespace kernal;

#define __module_class_register(_class)                                         \
function_creator_pool_[_class::k_html_tag_name] =                               \
    [](std::shared_ptr<hal_document>& doc) {                                    \
        auto _module = hal_creator<_class>::instance(doc);                      \
        auto _component = std::dynamic_pointer_cast<hal_component>(_module);    \
        if (_component && _component->init_construct()) {                       \
            return _component;                                                  \
        }                                                                       \
        return std::shared_ptr<hal_component>();                                \
    }

hal_component_creator::hal_component_creator() {
    __module_class_register(hal_html_div);
    __module_class_register(hal_html_image);
    __module_class_register(hal_html_label);
    __module_class_register(hal_html_input);
}

hal_component_creator::~hal_component_creator() {

}

std::shared_ptr<hal_component> hal_component_creator::instance
            (std::shared_ptr<hal_document>& doc, const char* tag) {
    if (!doc || nullptr == tag) {
        return std::shared_ptr<hal_component>();
    }
    function_creator_pool_t::iterator _it = function_creator_pool_.find(tag);
    if (function_creator_pool_.end() != _it) {
        return _it->second(doc);
    }
    return std::shared_ptr<hal_component>();
}
