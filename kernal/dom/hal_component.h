#ifndef Halberd_Kernal_Dom_Hal_Component_H_
#define Halberd_Kernal_Dom_Hal_Component_H_

#include <base/hal_inct.h>
#include <utils/hal_t_define.h>
#include <css/hal_css_t.h>
#include <event/hal_event.h>
#include <layout/hal_layout_define.h>

#include "hal_component_define.h"
#include "hal_element.h"
#include "hal_attributes_dispatch.h"

namespace kernal {
    class hal_flex;
    class hal_document;
    class hal_component : public hal_element {
    public:
        friend class hal_flex;

    public:
        hal_component();
        hal_component(std::shared_ptr<hal_document>&);
        virtual ~hal_component();

    public:
        virtual bool init_construct();

    public:
        virtual void layout_children(const hal_rect&, bool);
        virtual hal_size measure_size(const hal_size&, hal_measure_style);

    public:
        // note: event stream
        // note: bool is user for event rasie or sink
        // note: if return false the event will be discarded
        virtual bool event_stream(bool, std::shared_ptr<hal_event>& event);

        // note: set attributs k and v
        virtual bool set_attributes(const char* k, const char* val);

        // note: set css attributs k and v
        virtual bool set_style_attributes(const char* k, const char* val);

    public:
        // note: this function is called by attributs dispatcher
        // note: this function should parser css string into kv
        // note: the ret of parser
        void internal_attr_set_style(const char* str);

    public:
        std::string doc_id() const;

    public:
        hal_rect rect() const;

        hal_rect document_relative_rect() const;

    protected:
        // note: this function is use to sync crash tree
        bool sync_area_index(bool remove) const;

        // note: on removed
        void internal_removed();

        // note: remove all chidren from crash tree
        void internal_remove_area_tree_recursive(
            std::shared_ptr<hal_component>&, std::shared_ptr<hal_document>&);

    protected:
        hal_css_t css_;

    protected:
        std::string doc_id_;
        bool is_sync_area_index_ = false;
        hal_rect_t rect_, document_relative_rect_;
        std::weak_ptr<hal_document> host_document_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Component_H_
