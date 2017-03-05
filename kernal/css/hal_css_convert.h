#ifndef Halberd_Kernal_Css_Hal_Css_Convert_H_
#define Halberd_Kernal_Css_Hal_Css_Convert_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>

namespace kernal
{
    class hal_css_convert final {
    public:
        // note: convert string => int
        static bool convert(const char*, int32_t*);

        // note: convert string => float
        static bool convert(const char*, float*);

        // note: convert string => double
        static bool convert(const char*, double*);

        // note: convert string => color
        static bool convert(const char*, hal_color*);

        // note: convert string => size
        static bool convert(const char*, hal_size*);

        // note: convert string => divide
        static bool convert(const char*, hal_divide*);
    };
}
#endif//Halberd_Kernal_Css_Hal_Css_Convert_H_
