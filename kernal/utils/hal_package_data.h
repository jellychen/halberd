#ifndef Halberd_Kernal_Utils_Hal_Package_Data_H_
#define Halberd_Kernal_Utils_Hal_Package_Data_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_package_data final {
    public:
        hal_package_data();
        virtual ~hal_package_data();

    public:
        void clear();

    public:
        void resize(uint32_t);

    public:
        uint32_t size();
        uint8_t* raw_buffer();

    public:
        bool append_buffer(const uint8_t*, uint32_t);
        bool copy_from_raw_buffer(const uint8_t*, uint32_t);

    protected:
        std::string inner_buffer_;
    };
}
#endif//Halberd_Kernal_Utils_Hal_Package_Data_H_
