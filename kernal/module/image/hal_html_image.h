#ifndef Halberd_Kernal_Module_Div_Hal_Html_Image_H_
#define Halberd_Kernal_Module_Div_Hal_Html_Image_H_

#include <base/hal_inct.h>
#include <component/hal_component.h>
#include <render_recoder/hal_render_recoder_inct.h>

namespace kernal {
    class hal_html_image final : public hal_component {
    public:
        static const char* k_html_tag_name;
    public:
        using _parent = hal_component;
        using hal_component::hal_component;

    public:
        bool init_construct();

    public:
        bool set_image_url(const char* url);

        bool set_image_buffer(const char* buffer, uint32_t size);

    private:
        std::shared_ptr<hal_render_command_texture> texture_;
    };
}
#endif//Halberd_Kernal_Module_Div_Hal_Html_Div_H_
