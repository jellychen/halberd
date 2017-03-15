#include "dom/hal_document.h"
#include "hal_component_render.h"
using namespace kernal;

std::shared_ptr<hal_render_command_buffer>
    hal_component_render::render_command_buffer() {
    if (host_document_.expired()) {
        return std::shared_ptr<hal_render_command_buffer>();
    }
    return host_document_.lock()->command_buffer();
}

void hal_component_render::render(
    std::shared_ptr<hal_render_command_context>& context) {
    if (context) {
        context->save_state();

        // note: clip canvas
        
        // note: render background

        render(context);

        // note: render outline

        context->restore_state();
    }
}

void hal_component_render::paint(
    std::shared_ptr<hal_render_command_context>& context) {
}

void hal_component_render::invalidate_render() {
}
