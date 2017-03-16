#ifndef Halberd_Kernal_Dom_Hal_Document_H_
#define Halberd_Kernal_Dom_Hal_Document_H_

#include "base/hal_inct.h"
#include "component/hal_component.h"
#include "render_recoder/hal_render_recoder_inct.h"

#include "hal_document_head.h"
#include "hal_document_content.h"
#include "hal_document_id_index.h"
#include "hal_document_area_index.h"

namespace kernal {
    class hal_document final
        : public std::enable_shared_from_this<hal_document> {
    public:
        hal_document();
        hal_document(
            std::shared_ptr<hal_render_command_buffer>&);
        virtual ~hal_document();

    public:
        std::shared_ptr<hal_render_command_buffer> command_buffer();

    public:
        // note: layout document
        bool layout(hal_size& size);

    public:
        // note: resize canvas
        bool resize_view_size(hal_size& size);

    public:
        // note: capture current canvas
        bool capture_canvas_to_file(const char* name);

    public:
        // note: id index pool
        hal_document_id_index id_index_;

        // note: rtree index pool
        hal_document_area_index area_index_;

        // note: document head
        std::shared_ptr<hal_document_head> doc_head_;

        // note: docuemnt content
        std::shared_ptr<hal_document_content> doc_content_;

    private:
        std::shared_ptr<hal_render_command_buffer> command_buffer_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Document_H_
