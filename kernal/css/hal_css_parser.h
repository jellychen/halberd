#ifndef Halberd_Kernal_Css_Hal_Css_Parser_H_
#define Halberd_Kernal_Css_Hal_Css_Parser_H_

#include "base/hal_inct.h"
#include "component/hal_component_attributes.h"

namespace kernal {
    class hal_css_parser final {
    public:
        virtual ~hal_css_parser();

    public:

        // note: pasert html inner style
        // note: like <div style="width:10px" ...
        bool declaration_list(
            const char*, size_t,
            std::shared_ptr<hal_component_attributes>);
    };
}
#endif//Halberd_Kernal_Css_Hal_Css_Parser_H_
