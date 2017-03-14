#ifndef Halberd_Kernal_Component_Hal_Component_Base_H_
#define Halberd_Kernal_Component_Hal_Component_Base_H_

#include "base/hal_inct.h"
#include "dom/hal_element.h"

namespace kernal {
    class hal_document;
    class hal_component_base : public hal_element {
    public:
        hal_component_base();
        hal_component_base(std::shared_ptr<hal_document>&);
        virtual ~hal_component_base();

    public:
        virtual bool init_construct();

    public:
        std::string doc_id() const;

    protected:
        // note: indicate id
        std::string doc_id_;

        // note: host document
        std::weak_ptr<hal_document> host_document_;
    };
}
#endif//Halberd_Kernal_Component_Hal_Component_Base_H_
