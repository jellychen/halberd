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
    // note: save state
    context->save_state();

    // note: clip cnavas

    // note: render
    if (context && is_need_render) {
        // note: render background
        render(context);

        // note: render outline
    }
    is_need_render = false;

    // note: render children
    if (context) {
        std::vector<std::shared_ptr<hal_component_render>> need_render_children;
        for (size_t index = 0; index < children_.size(); ++index) {
            std::shared_ptr<hal_element>& ele = children_[index];
            auto renderable = std::dynamic_pointer_cast<hal_component_render>(ele);
            if (renderable) {
                if (renderable->is_need_render
                    && renderable->is_have_child_need_render) {
                    need_render_children.push_back(renderable);
                }
            }
        }

        // note: sort
        using render_item_t = std::shared_ptr<hal_component_render>;
        std::sort(need_render_children.begin(), need_render_children.end(),
            [](const render_item_t &v1, const render_item_t &v2) {
                return v1->css_z_index() < v2->css_z_index();
        });

        // note: render all need render
        for (size_t index = 0; index < need_render_children.size(); ++index) {
            need_render_children[index]->render(context);
        }
    }
    is_have_child_need_render = false;

    // note: restore state
    context->restore_state();
}

void hal_component_render::mark_need_render() {
    is_need_render = true;
    if (false == is_have_child_need_render) {
        mark_parent_hava_children_need_render();
    }
}

void hal_component_render::paint(
    std::shared_ptr<hal_render_command_context>& context) {
}

void hal_component_render::invalidate_render() {
    // note: mark
    mark_need_render();

    // note: area crash
    if (!host_document_.expired()) {
        host_document_.lock()
            ->area_index_.mark_need_render(visible_rect_);
    }
}

void hal_component_render::mark_parent_hava_children_need_render() {
    if (!parent_.expired()) {
        std::shared_ptr<hal_element> parent = parent_.lock();
        auto renderable = std::dynamic_pointer_cast<hal_component_render>(parent);
        if (renderable) {
            if (!renderable->is_have_child_need_render) {
                mark_parent_hava_children_need_render();
                renderable->is_have_child_need_render = true;
            }
        }
    }
}
