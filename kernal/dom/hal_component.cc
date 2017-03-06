#include "hal_document.h"
#include "hal_component.h"
using namespace kernal;

hal_component::hal_component() {

}

hal_component::hal_component(
    std::shared_ptr<hal_document>& doc):host_document_(doc) {

}

hal_component::~hal_component() {
    // note: dealloc remove self from id index
    if (!host_document_.expired() && !doc_id_.empty()) {
        host_document_.lock()->id_index_.remove(doc_id_);
    }
}

bool hal_component::init_construct() {
    return true;
}

std::string hal_component::doc_id() const {
    return doc_id_;
}

hal_rect hal_component::rect() const {
    return rect_;
}

hal_rect hal_component::document_relative_rect() const {
    return document_relative_rect_;
}

bool hal_component::sync_area_index(bool remove) const {
    if (is_sync_area_index_ || host_document_.expired()) {
        return false;
    }
    return true;
}

// note: when dom node is removed
// note: if node have sync into crash tree
// note: the children of node must be remove from crash tree
// note: if the removed node's parent is not sync into crash tree
// note: the var is_sync_area_index_ == false
// note: when layout the node, will add into crash tree
void hal_component::internal_removed() {
    hal_element::internal_removed();

    if (is_sync_area_index_ || !(host_document_.expired())) {
        auto host_document = host_document_.lock();
        std::shared_ptr<hal_component> component
            = std::dynamic_pointer_cast<hal_component>(shared_from_this());
        host_document->area_index_.remove(document_relative_rect_, component);
        is_sync_area_index_ = false;

        for (size_t i = 0; i < children_.size(); ++i) {
            auto component = std::dynamic_pointer_cast<hal_component>(children_[i]);
            if (component) {
                internal_remove_area_tree_recursive(component, host_document);
            }
        }
    }
}

// note: recursive remove all children
// note: this function is use to reduce dynamic_cast
void hal_component::internal_remove_area_tree_recursive(
    std::shared_ptr<hal_component>& component, std::shared_ptr<hal_document>& document) {
    if (document && component && component->is_sync_area_index_) {
        document->area_index_.remove(component->document_relative_rect_, component);
        component->is_sync_area_index_ = false;

        for (size_t i = 0; i < children_.size(); ++i) {
            auto child = std::dynamic_pointer_cast<hal_component>(component->children_[i]);
            if (child) {
                internal_remove_area_tree_recursive(child, document);
            }
        }
    }
}
