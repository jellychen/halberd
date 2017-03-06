#ifndef Halberd_Kernal_Dom_Hal_Document_Area_Index_H_
#define Halberd_Kernal_Dom_Hal_Document_Area_Index_H_

#include <base/hal_inct.h>
#include <external/rtree/r_tree.h>

#include "hal_component.h"

namespace kernal {
    class hal_document_area_index final {
    public:
        hal_document_area_index();
        virtual ~hal_document_area_index();

    public:
        // note: add rect area into rtree
        bool add(const hal_rect&, std::shared_ptr<hal_component>&);

        // note: remove rect area into rtree
        bool remove(const hal_rect&, std::shared_ptr<hal_component>&);

        // note: remove all
        bool remove_all();

        // note: count of all
        uint32_t count();

    private:
        RTree<std::shared_ptr<hal_component>, float, 2> area_tree_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Document_Area_Index_H_
