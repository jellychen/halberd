#ifndef Halberd_Kernal_Component_Hal_Component_Creator_H_
#define Halberd_Kernal_Component_Hal_Component_Creator_H_

#include <base/hal_inct.h>
#include <dom/hal_element.h>
#include <dom/hal_document.h>

#include "hal_component.h"

namespace kernal {
    class hal_component_creator final {
    public:
        hal_component_creator();
        virtual ~hal_component_creator();

    public:
        std::shared_ptr<hal_component> instance(
                std::shared_ptr<hal_document>& doc, const char*);

    private:
        using function_creator_t = std::function<
            std::shared_ptr<hal_component>(std::shared_ptr<hal_document>&)>;
        using function_creator_pool_t = std::map<std::string, function_creator_t>;
    private:
        function_creator_pool_t function_creator_pool_;
    };
}
#endif//Halberd_Kernal_Component_Hal_Component_Creator_H_
