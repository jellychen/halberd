#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_isolate_maintain;

    // note: base interface of handler
    class hal_isolate_handler {
    public:
        virtual void post(
            std::function<void(hal_isolate_maintain*)>&) =0;
    };

    // note: it is for singleton
    class hal_isolate_handler_fetcher final {
    friend class hal_isolate_maintain;
    private:
        bool attach(std::weak_ptr<hal_isolate_handler>&);
    public:
        std::weak_ptr<hal_isolate_handler> current();
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Isolate_Handler_H_
