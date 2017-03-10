#ifndef Halberd_Kernal_Render_Al_Canvas_Hal_Render_Canvas_H_
#define Halberd_Kernal_Render_Al_Canvas_Hal_Render_Canvas_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "render_al/hal_render_require.h"

namespace kernal {
    class hal_render_context_base;
    class hal_render_canvas {
    public:
        friend class hal_render_context_base;
    public:
        virtual void resize(const hal_size& size) =0;
        virtual void capture_to_file(const char* file) =0;

    public:
        virtual hal_size size() const =0;

    private:
        virtual SkCanvas* raw_unsafe_canvas() =0;
    };
}
#endif//Halberd_Kernal_Render_Al_Canvas_Hal_Render_Canvas_H_
