#ifndef Halberd_Kernal_Component_Hal_Component_H_
#define Halberd_Kernal_Component_Hal_Component_H_

#include "base/hal_inct.h"
#include "hal_component_event.h"

namespace kernal {
    class hal_component : public hal_component_event {
    public:
        using hal_component_event::hal_component_event;

    private:
        // note: override removed
        void internal_removed() override;

        // note: override id change
        void internal_attr_id_change() override;

    private:
        void internal_remove_area_tree_recursive(
            std::shared_ptr<hal_component>&,
            std::shared_ptr<hal_document>&);

    private:
        bool is_sync_area_index_ = false;
    };
}
#endif//Halberd_Kernal_Component_Hal_Component_H_
