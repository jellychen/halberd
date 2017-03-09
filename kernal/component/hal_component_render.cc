#include <isolate/hal_isolate.h>
#include <dom/hal_document.h>

#include "hal_component.h"
using namespace kernal;

void hal_component::invalidate_render() {

}

std::shared_ptr<hal_render_command_buffer> hal_component::render_command_buffer() {
    if (host_document_.expired()) {
        return std::shared_ptr<hal_render_command_buffer>();
    }
    auto isolate = host_document_.lock()->host_isolate();

    if (isolate) {

    }
    return std::shared_ptr<hal_render_command_buffer>();
}
