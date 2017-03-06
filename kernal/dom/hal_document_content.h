#ifndef Halberd_Kernal_Dom_Hal_Component_Content_H_
#define Halberd_Kernal_Dom_Hal_Component_Content_H_

#include <base/hal_inct.h>

namespace kernal {
    class hal_component;

    class hal_document_content : public hal_component {
    public:
        using _parent = hal_component;
        using hal_component::hal_component;

    public:
        bool init_construct();
    };
}
#endif//Halberd_Kernal_Dom_Hal_Component_Content_H_
