#include "hal_document.h"
#include "hal_component.h"
using namespace kernal;

hal_component::hal_component() {

}

hal_component::hal_component(
    std::shared_ptr<hal_document>& doc):host_document_(doc) {

}

hal_component::~hal_component() {

}

bool hal_component::init_construct() {
    return true;
}

std::string hal_component::doc_id() const {
    return doc_id_;
}
