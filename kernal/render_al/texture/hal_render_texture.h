#ifndef Halberd_Kernal_Render_Al_Texture_Hal_Render_Texture_H_
#define Halberd_Kernal_Render_Al_Texture_Hal_Render_Texture_H_

#include <render_al/context/hal_render_context.h>

namespace kernal {
    class hal_render_texture {
    public:
        hal_render_texture();
        virtual ~hal_render_texture();

    public:
        bool clear();
        bool is_have_data() const;
        bool load_file(const char* file);
        bool load_buffer(const char* buffer, uint32_t size);

    public:
        hal_size size() const;

    public:
        // draw on context,
        // std::shared_ptr<hal_render_context>      => context
        // uint8_t                                  => alpha
        // bool                                     => aa
        // float                                    => left
        // float                                    => top
        bool draw(std::shared_ptr<hal_render_context>&, uint8_t, bool, float, float);

        // draw on context,
        bool draw(std::shared_ptr<hal_render_context>& context,
            uint8_t alpha, bool aa, const hal_rect& src, const hal_rect& dest);

    public:
        sk_sp<SkImage> texture_;
    };
}
#endif//Halberd_Kernal_Render_Al_Texture_Hal_Render_Texture_H_
