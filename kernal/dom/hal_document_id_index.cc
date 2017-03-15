#include "hal_document_id_index.h"
using namespace kernal;

bool hal_document_id_index::add(
    std::string& _id, std::shared_ptr<hal_component_base>& component) {
    if (_id.empty() || !component) {
        return false;
    }
    std::weak_ptr<hal_component_base> w_component = component;
    id_index_pool_[_id] = w_component;
    return true;
}

bool hal_document_id_index::remove(std::string& _id) {
    auto iter = id_index_pool_.find(_id);
    if (id_index_pool_.end() != iter) {
        id_index_pool_.erase(iter);
    }
    return true;
}

std::shared_ptr<hal_component> hal_document_id_index::find(std::string& _id) {
    auto iter = id_index_pool_.find(_id);
    if (id_index_pool_.end() != iter) {
        return std::dynamic_pointer_cast<hal_component>(iter->second.lock());
    }
    return std::shared_ptr<hal_component>();
}

uint32_t hal_document_id_index::count() const {
    return (uint32_t)id_index_pool_.size();
}
