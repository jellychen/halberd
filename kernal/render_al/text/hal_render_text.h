#ifndef Halberd_Kernal_Render_Al_Text_Hal_Render_Text_H_
#define Halberd_Kernal_Render_Al_Text_Hal_Render_Text_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <render_al/hal_render_require.h>

#include "hal_render_text_font.h"

namespace kernal
{
    class hal_render_text final {
    public:
        hal_render_text();
        virtual ~hal_render_text();

    public:


    private:
        std::string str_;
    };
}
#endif//Halberd_Kernal_Render_Al_Text_Hal_Render_Text_H_
