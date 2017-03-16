#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Raster_Thread_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Raster_Thread_H_

#include "base/hal_inct.h"
#include "hal_render_command_buffer.h"
#include "render_al/context/hal_render_context.h"

namespace kernal {
    class hal_render_raster_thread final {
    public:
        hal_render_raster_thread(
            std::shared_ptr<hal_render_context>&,
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_render_raster_thread();

    public:
        bool stop_and_wait();

    private:
        std::thread thread_;
        std::atomic_bool should_exit_ = {false};
        std::shared_ptr<hal_render_context> render_context_;
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Raster_Thread_H_
