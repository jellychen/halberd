#include "dom/hal_document.h"
#include "hal_component_base.h"
using namespace kernal;

hal_component_base::hal_component_base() {

}

hal_component_base::hal_component_base(
    std::shared_ptr<hal_document>& doc):host_document_(doc) {
}

hal_component_base::~hal_component_base() {
    if (!host_document_.expired() && !doc_id_.empty()) {
        host_document_.lock()->id_index_.remove(doc_id_);
    }
}

bool hal_component_base::init_construct() {
    return true;
}

std::string hal_component_base::doc_id() const {
    return doc_id_;
}

// note: on removed
void hal_component_base::internal_removed() {

}

// note: remove all children from crash tree
void internal_remove_area_tree_recursive(
    std::shared_ptr<hal_component_base>&,
    std::shared_ptr<hal_component_base>&) {

}
