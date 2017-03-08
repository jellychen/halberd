#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_Texture_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_Texture_H_

#include <base/hal_inct.h>
#include <render_al/context/hal_render_context.h>
#include <render_al/texture/hal_render_texture.h>

#include "hal_render_command_draw.h"

namespace kernal {
    class hal_render_command_texture final {
    public:
        hal_render_command_texture(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_render_command_texture();

    public:
        bool clear();
        bool is_have_data() const;
        bool load_file(const char* file);
        bool load_buffer(const char* buffer, uint32_t size);

    public:
        hal_size size() const;

    public:
        // draw on context
        // uint8_t                                  => alpha
        // bool                                     => aa
        // float                                    => left
        // float                                    => top
        bool draw(uint8_t, bool, float, float);

        // draw on context,
        bool draw(uint8_t alpha, bool aa, const hal_rect src, const hal_rect dest);

    protected:
        hal_render_texture raw_texture_;
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_Texture_H_
