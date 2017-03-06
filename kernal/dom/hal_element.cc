#include "hal_element.h"
using namespace kernal;

hal_element::hal_element() {

}

hal_element::~hal_element() {

}

std::shared_ptr<hal_element> hal_element::last() {
    if (parent_.expired()) {
        return std::shared_ptr<hal_element>();
    }

    bool finded = false;
    std::shared_ptr<hal_element> ele = shared_from_this();
    uint32_t index = parent_.lock()->find_index(ele, &finded);
    if (finded && index > 0) {
        return children_[--index];
    }
    return std::shared_ptr<hal_element>();
}

std::shared_ptr<hal_element> hal_element::next() {
    if (parent_.expired()) {
        return std::shared_ptr<hal_element>();
    }

    bool finded = false;
    std::shared_ptr<hal_element> ele = shared_from_this();
    uint32_t index = parent_.lock()->find_index(ele, &finded);
    if (finded && index < uint32_t(children_.size())) {
        return children_[++index];
    }
    return std::shared_ptr<hal_element>();
}

std::shared_ptr<hal_element> hal_element::parent() {
    return std::shared_ptr<hal_element>(parent_);
}

std::shared_ptr<hal_element> hal_element::at(uint32_t index) {
    if (index >= (uint32_t)children_.size()) {
        return std::shared_ptr<hal_element>();
    }
    return children_[index];
}

std::shared_ptr<hal_element> hal_element::remove(uint32_t index) {
    if (index >= (uint32_t)children_.size()) {
        return std::shared_ptr<hal_element>();
    }
    auto _rm_element = children_[index];
    if (_rm_element) {
        _rm_element->internal_removed();
        _rm_element->parent_.reset();
    }
    children_.erase(children_.begin() + index);
    hal_element::internal_have_child_removed();
    return _rm_element;
}

bool hal_element::remove_from_parent() {
    if (!parent_.expired()) {
        return false;
    }
    auto _rm_element = shared_from_this();
    return parent_.lock()->remove_child(_rm_element);
}

bool hal_element::remove_all_children() {
    bool have_child_removed = (bool)children_.size();
    for (size_t i =0; i < children_.size(); ++i) {
        if (children_[i]) {
            children_[i]->internal_removed();
            children_[i]->parent_.reset();
        }
    }
    if (have_child_removed) {
        hal_element::internal_have_child_removed();
    }
    return true;
}

bool hal_element::remove_child(std::shared_ptr<hal_element>& child) {
    bool finded = false;
    uint32_t index = hal_element::find_index(child, &finded);
    if (true == finded) {
        return (bool)hal_element::remove(index);
    }
    return false;
}

bool hal_element::append_child(std::shared_ptr<hal_element>& child) {
    if (!child || child->parent_.expired()) {
        return false;
    }

    children_.push_back(child);
    child->parent_ = shared_from_this();
    child->internal_mounted();
    hal_element::internal_have_child_mounted();
    return true;
}

bool hal_element::insert_child_at_index(
    uint32_t index, std::shared_ptr<hal_element>& child) {
    if (!child || child->parent_.expired()) {
        return false;
    }

    if (index > (uint32_t)(children_.size())) {
        children_.push_back(child);
    } else {
        children_.insert(children_.begin() +index, child);
    }

    child->parent_ = shared_from_this();
    child->internal_mounted();
    hal_element::internal_have_child_mounted();
    return true;
}

uint32_t hal_element::children_count() const {
    return (uint32_t)children_.size();
}

uint32_t hal_element::find_index(
    const std::shared_ptr<hal_element>& element, bool* finded) const {

    if (nullptr != finded) {
        *finded = false;
    }

    if (!element) {
        return 0;
    }

    for (size_t i =0; i < children_.size(); ++i) {
        if (element == children_[i]) {
            if (nullptr != finded) {
                *finded = true;
            }
            return (uint32_t)i;
        }
    }
    return 0;
}

void hal_element::foreach_children(
    std::function<void(std::shared_ptr<hal_element>&)> function) {
    if (function) {
        for (size_t i =0; i < children_.size(); ++i) {
            if (children_[i]) {
                function(children_[i]);
            }
        }
    }
}

void hal_element::foreach_children_deep(
    std::function<void(std::shared_ptr<hal_element>&)> function) {
    if (function) {
        for (size_t i =0; i < children_.size(); ++i) {
            std::shared_ptr<hal_element> child = children_[i];
            if (child) {
                function(child);
                child->foreach_children_deep(function);
            }
        }
    }
}
