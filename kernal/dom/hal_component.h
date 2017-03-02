#ifndef Halberd_Kernal_Dom_Hal_Component_H_
#define Halberd_Kernal_Dom_Hal_Component_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <event/hal_event.h>

#include "hal_element.h"
#include "hal_attributes_dispatch.h"

namespace kernal
{
    enum hal_measure_style {
        hal_measure_width_assgin    = 0x1,
        hal_measure_height_assgin   = 0x2,
    };

    class hal_document;

    class hal_component : public hal_element {
    public:
        hal_component();
        hal_component(std::shared_ptr<hal_document>&);
        virtual ~hal_component();

    public:
        virtual bool init_construct();

    public:
        virtual void layout_children(const hal_rect&, bool);
        virtual hal_size measure_size(const hal_size&, hal_measure_style);

    public:
        // note: event stream
        // note: bool is user for event rasie or sink
        // note: if return false the event will be discarded
        virtual bool event_stream(bool, std::shared_ptr<hal_event>& event);

        // note: set attributs k and v
        virtual bool set_attributes(const char* k, const char* val);

        // note: set css attributs k and v
        virtual bool set_style_attributes(const char* k, const char* val);

    public:
        // note: this function is called by attributs dispatcher
        // note: this function should parser css string into kv
        // note: the ret of parser
        void internal_attr_set_style(const char* str);

    protected:
        std::string doc_id_;
        std::weak_ptr<hal_document> host_document_;

    public:
        std::string doc_id() const;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Component_H_
