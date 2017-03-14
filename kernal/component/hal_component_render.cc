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

void hal_component_render::invalidate_render() {

}
