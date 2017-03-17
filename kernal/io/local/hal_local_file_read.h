#ifndef Halberd_Kernal_Io_Local_Hal_Local_File_Read_H_
#define Halberd_Kernal_Io_Local_Hal_Local_File_Read_H_

#include "base/hal_inct.h"
#include "utils/hal_package_data.h"

namespace kernal {
    namespace io {

        class hal_local_file_read final {
        public:
            hal_local_file_read();
            virtual ~hal_local_file_read();

        public:
            std::shared_ptr<hal_package_data> read(const char* name);
        };
    }
}
#endif//Halberd_Kernal_Io_Local_Hal_Local_File_Read_H_
