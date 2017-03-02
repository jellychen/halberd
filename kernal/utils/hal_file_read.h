#ifndef Halberd_Kernal_Utils_Hal_File_Read_H_
#define Halberd_Kernal_Utils_Hal_File_Read_H_

#include <base/hal_inct.h>

namespace kernal
{
    class hal_file_read final {
    public:
        static bool read_whole(const char* file, std::string& buffer);
    };
}
#endif//Halberd_Kernal_Utils_Hal_File_Read_H_
