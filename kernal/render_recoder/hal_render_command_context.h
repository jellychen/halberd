#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>

#include "hal_render_command_path.h"

namespace kernal {
    class hal_render_command_context
        : public hal_render_command_path {
    public:
        using _parent = hal_render_command_path;
        using hal_render_command_path::hal_render_command_path;

    public:
        bool save_state();
        bool restore_state();

    public:
        bool rotate(float d);
        bool skew(float x, float y);
        bool scale(float x, float y);
        bool translate(float x, float y);
        bool camera_rotate(float x, float y, float z);
        bool camera_translate(float x, float y, float z);
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Context_H_
