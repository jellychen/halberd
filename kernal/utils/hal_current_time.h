#ifndef Halberd_Kernal_Utils_Hal_Current_Time_H_
#define Halberd_Kernal_Utils_Hal_Current_Time_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_current_time final {
    public:
        hal_current_time();
        virtual ~hal_current_time();

    public:
        void reset();

    public:
        int64_t elapsed() const;

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> begin_;
    };
}
#endif//Halberd_Kernal_Utils_Hal_Current_Time_H_
