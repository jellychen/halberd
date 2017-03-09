#ifndef Halberd_Kernal_Dom_Hal_Document_H_
#define Halberd_Kernal_Dom_Hal_Document_H_

#include <base/hal_inct.h>
#include <component/hal_component.h>

#include "hal_document_head.h"
#include "hal_document_content.h"
#include "hal_document_id_index.h"
#include "hal_document_area_index.h"

namespace kernal {

    class hal_isolate;
    class hal_document final
        : public std::enable_shared_from_this<hal_document> {
    public:
        hal_document();
        hal_document(std::shared_ptr<hal_isolate>&);
        virtual ~hal_document();

    public:
        std::shared_ptr<hal_isolate> host_isolate();

    public:
        hal_document_id_index id_index_;
        hal_document_area_index area_index_;

    public:
        std::shared_ptr<hal_document_head> doc_head_;
        std::shared_ptr<hal_document_content> doc_content_;

    private:
        std::weak_ptr<hal_isolate> host_isolate_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Document_H_
