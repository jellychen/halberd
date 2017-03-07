#ifndef Halberd_Kernal_Render_Recoder_Hal_Render_Command_String_H_
#define Halberd_Kernal_Render_Recoder_Hal_Render_Command_String_H_

#include <base/hal_inct.h>

namespace kernal {
    class hal_render_command_string_t final {
    public:
        hal_render_command_string_t();
        hal_render_command_string_t(const char*);
        hal_render_command_string_t(
            const hal_render_command_string_t&);

    public:
        ~hal_render_command_string_t();

    public:
        hal_render_command_string_t& operator= (const char*);
        hal_render_command_string_t& operator= (
            const hal_render_command_string_t&);

    public:
        char* c_str() const;

    private:
        char* raw_buffer_ = nullptr;
    };
}
#endif//Halberd_Kernal_Render_Recoder_Hal_Render_Command_String_H_
