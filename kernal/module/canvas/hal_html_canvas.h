#ifndef Halberd_Kernal_Module_Div_Hal_Html_Canvas_H_
#define Halberd_Kernal_Module_Div_Hal_Html_Canvas_H_

#include <base/hal_inct.h>
#include <dom/hal_component.h>

namespace kernal {
    class hal_html_canvas final : public hal_component {
    public:
        static const char* k_html_tag_name;
    public:
        using _parent = hal_component;
        using hal_component::hal_component;

    public:
        bool init_construct();
    };
}
#endif//Halberd_Kernal_Module_Div_Hal_Html_Canvas_H_
