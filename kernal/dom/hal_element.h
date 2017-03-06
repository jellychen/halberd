#ifndef Halberd_Kernal_Dom_Hal_Element_H_
#define Halberd_Kernal_Dom_Hal_Element_H_

#include <base/hal_inct.h>

namespace kernal {
    class hal_element;
    using hal_element_children_t = std::vector<std::shared_ptr<hal_element>>;
    class hal_element: public std::enable_shared_from_this<hal_element> {
    public:
        hal_element();
        virtual ~hal_element();

    public:
        std::shared_ptr<hal_element> last();
        std::shared_ptr<hal_element> next();
        std::shared_ptr<hal_element> parent();
        std::shared_ptr<hal_element> at(uint32_t index);
        std::shared_ptr<hal_element> remove(uint32_t index);

    public:
        bool remove_from_parent();
        bool remove_all_children();
        bool remove_child(std::shared_ptr<hal_element>& child);
        bool append_child(std::shared_ptr<hal_element>& child);
        bool insert_child_at_index(uint32_t, std::shared_ptr<hal_element>&);

    public:
        uint32_t children_count() const;

        // note: return element index in array of children_
        // if finded == true the return value is the index
        uint32_t find_index(
            const std::shared_ptr<hal_element>&, bool* finded) const;

    public:
        // note: noly foreach children array
        // note: must not call remove function in callback
        void foreach_children(
            std::function<void(std::shared_ptr<hal_element>&)>);

        // note: foreach all element tree
        // note: must not call remove function in callback
        void foreach_children_deep(
            std::function<void(std::shared_ptr<hal_element>&)>);

    protected:
        virtual void internal_mounted() {}
        virtual void internal_removed() {}
        virtual void internal_have_child_removed() {}
        virtual void internal_have_child_mounted() {}

    protected:
        // children
        hal_element_children_t children_;

        // parent
        std::weak_ptr<hal_element> parent_;
    };
}
#endif//Halberd_Kernal_Dom_Hal_Element_H_
