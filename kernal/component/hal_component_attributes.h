#ifndef Halberd_Kernal_Component_Hal_Component_Attributes_H_
#define Halberd_Kernal_Component_Hal_Component_Attributes_H_

#include "base/hal_inct.h"
#include "css/hal_css_t.h"
#include "layout/hal_flex.h"
#include "hal_component_base.h"
#include "hal_attributes_dispatch.h"

namespace kernal {
    class hal_component_attributes : public hal_component_base {
    friend class hal_flex;
    public:
        using hal_component_base::hal_component_base;

    public:
        // note: set attributs k and v
        virtual bool set_attributes(const char* k, const char* val);

        // note: set css attributs k and v
        virtual bool set_style_attributes(const char* k, const char* val);

        // note: this function is called by attributs dispatcher
        // note: this function should parser css string into kv
        // note: the ret of parser
        void internal_attr_set_style(const char* str);

        // note: this function is called by attributs dispatcher
        // note: this is call by html attribution 'id'
        void internal_attr_set_id(const char* str);

    protected:
        // note: when id change
        virtual void internal_attr_id_change();

    protected:
        // note: css style
        hal_css_t css_;
    };
}
#endif//Halberd_Kernal_Component_Hal_Component_Attributes_H_
