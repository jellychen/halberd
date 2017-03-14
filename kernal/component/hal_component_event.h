#ifndef Halberd_Kernal_Component_Hal_Component_Event_H_
#define Halberd_Kernal_Component_Hal_Component_Event_H_

#include "base/hal_inct.h"
#include "event/hal_event.h"
#include "hal_component_render.h"

namespace kernal {
    class hal_component_event : public hal_component_render {
    public:
        using hal_component_render::hal_component_render;

    public:
        // note: event stream
        // note: bool is user for event rasie or sink
        // note: if return false the event will be discarded
        virtual bool event_stream(bool, std::shared_ptr<hal_event>&);
    };
}
#endif//Halberd_Kernal_Component_Hal_Component_Event_H_
