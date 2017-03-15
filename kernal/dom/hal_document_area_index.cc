#include "hal_document_area_index.h"
#include "component/hal_component_render.h"
using namespace kernal;

static bool __area_index_saerch(
    std::shared_ptr<hal_component_layout> component, void* that) {
    auto renderable = std::dynamic_pointer_cast<hal_component_render>(component);
    if (renderable) {
        renderable->mark_need_render();
    }
    return true;
}

hal_document_area_index::hal_document_area_index() {

}

hal_document_area_index::~hal_document_area_index() {

}

bool hal_document_area_index::add(
    const hal_rect& rect, std::shared_ptr<hal_component_layout>& component) {
    if (component) {
        float cood_min[2] = {rect.x_, rect.y_};
        float cood_max[2] = {rect.x_ + rect.width_, rect.y_ + rect.height_};
        area_tree_.Insert(cood_min, cood_max, component);
        return true;
    }
    return false;
}

bool hal_document_area_index::remove(
    const hal_rect& rect, std::shared_ptr<hal_component_layout>& component) {
    if (component) {
        float cood_min[2] = {rect.x_, rect.y_};
        float cood_max[2] = {rect.x_ + rect.width_, rect.y_ + rect.height_};
        area_tree_.Remove(cood_min, cood_max, component);
        return true;
    }
    return false;
}

bool hal_document_area_index::remove_all() {
    area_tree_.RemoveAll();
    return true;
}

uint32_t hal_document_area_index::count() {
    return (uint32_t)area_tree_.Count();
}

bool hal_document_area_index::mark_need_render(const hal_rect& rect) {
    float cood_min[2] = {rect.x_, rect.y_};
    float cood_max[2] = {rect.x_ + rect.width_, rect.y_ + rect.height_};
    area_tree_.Search(cood_min, cood_max, __area_index_saerch, nullptr);
    return false;
}
