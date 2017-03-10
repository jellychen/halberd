#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_H_

#include "base/hal_inct.h"
#include "dom/hal_document.h"
#include "render_recoder/hal_render_recoder_inct.h"

namespace kernal {
    class hal_isolate final
        : public std::enable_shared_from_this<hal_isolate> {
    public:
        hal_isolate();
        virtual ~hal_isolate();

    public:
        bool init();

    private:
        std::shared_ptr<hal_document> document_;
        std::shared_ptr<hal_render_raster_thread> raster_thread_;
        std::shared_ptr<hal_render_command_buffer> render_command_buffer_;
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Ioslate_H_
