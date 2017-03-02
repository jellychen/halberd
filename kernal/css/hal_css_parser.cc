#include <katana/src/katana.h>
#include <katana/src/parser.h>

#include "hal_css_parser.h"
using namespace kernal;

hal_css_parser::~hal_css_parser() {

}

bool hal_css_parser::declaration_list(
    const char* buffer, size_t len, std::shared_ptr<hal_component> component) {
    if (nullptr == buffer || 0 == len || !component) {
        return false;
    }

    KatanaOutput* _out = ::katana_parse(buffer, len, KatanaParserModeDeclarationList);
    if (nullptr == _out) {
        return false;
    }

    KatanaParser parser;
    parser.options = &kKatanaDefaultOptions;
    KatanaArray* declarations = _out->declarations;
    for (size_t i = 0; i < declarations->length; ++i) {
        auto decl = (KatanaDeclaration*)declarations->data[i];
        if (nullptr == decl) {
            continue;
        }
        component->set_style_attributes(decl->property, decl->raw);
    }
    return true;
}
