#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_Define_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_Define_H_

#include "base/hal_inct.h"
#include "render_al/context/hal_render_context.h"

namespace kernal {
    using hal_render_command
        = std::function<void(std::shared_ptr<hal_render_context>&)>;
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_Define_H_
