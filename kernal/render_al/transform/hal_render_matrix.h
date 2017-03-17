#ifndef Halberd_Kernal_Render_Al_Texture_Hal_Render_Matrix_H_
#define Halberd_Kernal_Render_Al_Texture_Hal_Render_Matrix_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "render_al/hal_render_require.h"

namespace kernal {
    class hal_render_matrix final {
    public:
        hal_render_matrix();
        virtual ~hal_render_matrix();

    public:
        void set_identi();

    public:
        // note: rotate matrix
        void set_rotate(float d);
        void pre_rotate(float d);
        void post_rotate(float d);

        // note: scale matrix
        void set_scale(float x, float y);
        void pre_scale(float x, float y);
        void post_scale(float x, float y);

        // note: translate matrix
        void set_translate(float x, float y);
        void pre_translate(float x, float y);
        void post_translate(float x, float y);

    public:
        // note: contact
        void pre_contact(hal_render_matrix& matrix);
        void post_contact(hal_render_matrix& matrix);

    public:
        // note: camera rotate
        void set_camera_rotate(float x, float y, float z);
        void pre_camera_rotate(float x, float y, float z);
        void post_camera_rotate(float x, float y, float z);

        // note: camera translate
        void set_camera_translate(float x, float y, float z);
        void pre_camera_translate(float x, float y, float z);
        void post_camera_translate(float x, float y, float z);

    public:
        SkMatrix raw_matrix_;
    };
}
#endif//Halberd_Kernal_Render_Al_Texture_Hal_Render_Matrix_H_
