#ifndef Halberd_Kernal_Event_Hal_Event_H_
#define Halberd_Kernal_Event_Hal_Event_H_

#include "base/hal_inct.h"
#include "hal_event_define.h"

namespace kernal {
    class hal_event
        : public std::enable_shared_from_this<hal_event> {
    public:
        hal_event();
        virtual ~hal_event();

    public:

    };
}
#endif//Halberd_Kernal_Event_Hal_Event_H_
