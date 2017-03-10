#include "dom/hal_document.h"
#include "hal_component.h"
using namespace kernal;

void hal_component::invalidate_render() {

}

std::shared_ptr<hal_render_command_buffer> hal_component::render_command_buffer() {
    if (host_document_.expired()) {
        return std::shared_ptr<hal_render_command_buffer>();
    }
    return host_document_.lock()->command_buffer();
}
