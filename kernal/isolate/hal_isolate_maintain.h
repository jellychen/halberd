#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_Maintain_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_Maintain_H_

#include "base/hal_inct.h"
#include "hal_isolate_timer.h"
#include "hal_isolate_task_pool.h"
#include "dom/hal_document.h"
#include "render_recoder/hal_render_recoder_inct.h"

namespace kernal {
    class hal_isolate_maintain final
        : public std::enable_shared_from_this<hal_isolate_maintain> {
    public:
        hal_isolate_maintain(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_isolate_maintain();

    public:
        bool load_url(const char* url);
        bool load_from_file(const char* name);

    public:
        // note: resize
        bool resize_document_view_size(hal_size& size);

        // note: capture current canvas
        bool capture_canvas_to_file(const char* name);
        
    public:
        void post(std::function<void(hal_isolate_maintain*)>);

    private:
        std::thread thread_;
        std::atomic_bool should_exit_ = {false};
        std::shared_ptr<hal_document> document_;
        std::shared_ptr<hal_isolate_task_queue> task_queue_;
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Isolate_Maintain_H_
