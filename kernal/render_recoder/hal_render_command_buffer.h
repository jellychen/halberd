#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_

#include "base/hal_inct.h"
#include "render_al/context/hal_render_context.h"
#include "hal_render_command_buffer_define.h"

namespace kernal {
    class hal_render_command_buffer final {
    public:
        hal_render_command_buffer(bool multi_thread);
        virtual ~hal_render_command_buffer();

    public:
        void commit(hal_render_command&);

    public:
        // note: run buffer block in the same thread
        void run(std::shared_ptr<hal_render_context>&);

        // note: run buffer block in different thread
        void run_in_thread(std::shared_ptr<hal_render_context>&);

    public:
        // note: wake up thread
        void wake_up_thread();

    private:
        bool signal_ = false;
        bool is_multi_thread = false;
        mutable std::mutex mutex_;
        std::condition_variable condition_;
        std::queue<hal_render_command> *in_, *out_;
        std::queue<hal_render_command> command_queue_[2];
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Buffer_H_
