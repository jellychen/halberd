#include <dom/hal_document.h>

#include "hal_component.h"
using namespace kernal;

bool hal_component::event_stream(
    bool, std::shared_ptr<hal_event>& event) {
    return true;
}
