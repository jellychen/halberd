#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>

#include "hal_render_command_buffer_define.h"

namespace kernal {
    class hal_render_command_buffer final {
    public:
        hal_render_command_buffer();
        virtual ~hal_render_command_buffer();

    public:
        void commit(hal_render_command&);

    public:
        void run(std::shared_ptr<hal_render_context>&);

    private:
        std::queue<hal_render_command> command_queue_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_
