#ifndef Halberd_Kernal_Layout_Hal_Foundation_H_
#define Halberd_Kernal_Layout_Hal_Foundation_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"

namespace kernal {
    class hal_component;
    class hal_foundation {
    public:
        hal_foundation();
        virtual ~hal_foundation();

    public:
        bool measure();

    public:
        // note: layout children
        bool layout(std::shared_ptr<hal_component>&, const hal_rect&);
    };
}
#endif//Halberd_Kernal_Layout_Hal_Foundation_H_
