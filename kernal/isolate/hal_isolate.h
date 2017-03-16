#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_H_

#include "base/hal_inct.h"
#include "hal_isolate_maintain.h"
#include "render_al/hal_render_inct.h"
#include "render_recoder/hal_render_recoder_inct.h"

namespace kernal {
    class hal_isolate final
        : public std::enable_shared_from_this<hal_isolate> {
    public:
        hal_isolate();
        virtual ~hal_isolate();

    public:
        bool init();

    public:
        // note: load from network
        bool load_url(const char* url);

        // note: load from file system
        bool load_from_file(const char* name);

    private:
        // note: render canvas context
        // note: is used in raster thread
        std::shared_ptr<hal_render_canvas> render_canvas_;
        std::shared_ptr<hal_render_context> render_context_;

        // note: render command message queue
        std::shared_ptr<hal_render_command_buffer> render_command_buffer_;

        // note: logic thread. do script and layout
        std::shared_ptr<hal_isolate_maintain> isolate_maintain_;

        // note: render thread
        std::shared_ptr<hal_render_raster_thread> raster_thread_;
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Ioslate_H_
