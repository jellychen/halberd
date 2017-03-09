#ifndef Halberd_Kernal_Dom_Hal_Document_Id_Index_H_
#define Halberd_Kernal_Dom_Hal_Document_Id_Index_H_

#include <base/hal_inct.h>
#include <component/hal_component.h>

namespace kernal {
    class hal_document_id_index final {
    public:
        // note: add id in index pool
        bool add(std::string&, std::shared_ptr<hal_component>&);

        // note: remove id from index pool
        bool remove(std::string&);

        // note: pool size
        uint32_t count() const;

    public:
        std::shared_ptr<hal_component> find(std::string&);

    private:
        using id_index_t = std::map<std::string, std::weak_ptr<hal_component>>;

    private:
        id_index_t id_index_pool_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Document_Id_Index_H_
