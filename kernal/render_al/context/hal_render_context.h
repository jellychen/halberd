#ifndef Halberd_Kernal_Render_Al_Context_Hal_Render_Context_H_
#define Halberd_Kernal_Render_Al_Context_Hal_Render_Context_H_

#include "hal_render_context_path.h"

namespace kernal {
    class hal_render_context
        : public hal_render_context_path {
    public:
        using _parent = hal_render_context_clip;
        using hal_render_context_path::hal_render_context_path;

    public:
        bool rotate(float d);
        bool skew(float x, float y);
        bool scale(float x, float y);
        bool translate(float x, float y);

    public:
        bool camera_rotate(float x, float y, float z);
        bool camera_translate(float x, float y, float z);

    public:
        bool save_state();
        bool restore_state();
    };
}
#endif//Halberd_Kernal_Render_Al_Context_Hal_Render_Context_H_
