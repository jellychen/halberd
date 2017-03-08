#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Base_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Base_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>

#include "hal_render_command_buffer.h"
#include "hal_render_command_string.h"

namespace kernal {
    class hal_render_command_base {
    public:
        hal_render_command_base(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_render_command_base();

    public:
        void capture_to_file(const char* file);

    protected:
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Base_H_
