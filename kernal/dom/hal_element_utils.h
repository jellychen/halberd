#ifndef Halberd_Kernal_Dom_Hal_Element_Utils_H_
#define Halberd_Kernal_Dom_Hal_Element_Utils_H_

#include <base/hal_inct.h>

#include "hal_element.h"

namespace kernal {
    // note: util function
    // note: use to cast child to t shared_ptr
    template<class t>
    inline std::shared_ptr<t> cast_child_at(
        std::shared_ptr<hal_element>& ele, uint32_t index) {
        if (ele && ele->children_count() < index) {
            return std::dynamic_pointer_cast<t>(ele->at(index));
        }
        return std::shared_ptr<t>();
    }
}
#endif//Halberd_Kernal_Dom_Hal_Element_Utils_H_
