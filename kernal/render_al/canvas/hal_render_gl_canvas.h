#ifndef Halberd_Kernal_Render_Al_Canvas_Hal_Render_Gl_Canvas_H_
#define Halberd_Kernal_Render_Al_Canvas_Hal_Render_Gl_Canvas_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "hal_render_canvas.h"

namespace kernal {
    class hal_render_context_base;
    class hal_render_gl_canvas : public hal_render_canvas {
    public:
        friend class hal_render_context_base;
        hal_render_gl_canvas(
            const hal_size& size, bool premul_alpha = true);
        virtual ~hal_render_gl_canvas();

    public:
        void resize(const hal_size& size);
        void capture_to_file(const char* file);

    public:
        hal_size size() const;

    private:
        SkCanvas* raw_unsafe_canvas();

    private:
        hal_size_t size_;
        bool premul_alpha_ = true;
        sk_sp<SkSurface> surface_;
    };
}
#endif//Halberd_Kernal_Render_Al_Canvas_Hal_Render_Gl_Canvas_H_
