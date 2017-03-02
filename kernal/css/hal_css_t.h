#ifndef Halberd_Kernal_Css_Hal_Css_T_H_
#define Halberd_Kernal_Css_Hal_Css_T_H_

#include <base/hal_inct.h>
#include <dom/hal_component.h>

namespace kernal
{
    class hal_css_t final {
    public:
        virtual ~hal_css_t();

    public:
        bool set_attributes(const char*, const char*);
    };
}
#endif//Halberd_Kernal_Css_Hal_Css_T_H_
