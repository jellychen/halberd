#ifndef Halberd_Kernal_Layout_Hal_Flex_H_
#define Halberd_Kernal_Layout_Hal_Flex_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"
#include "hal_layout_define.h"
#include "hal_flex_layout_param.h"

namespace kernal {
    class hal_component_layout;

    class hal_flex final {
    public:
        hal_flex();
        hal_flex(std::shared_ptr<hal_component_layout>);
        virtual ~hal_flex();

    public:
        bool attach_component(std::shared_ptr<hal_component_layout>);

    public:
        bool measure();

    public:
        // note: layout children
        // note: 0 => view_port size
        // note: 1 => relative rect
        // note: 2 => visible rect
        bool layout(const hal_size&, const hal_rect&, const hal_rect&);

    private:
        // note: layout children
        bool layout_row             (const hal_flex_layout_param&);
        bool layout_row_wrap        (const hal_flex_layout_param&);
        bool layout_row_nowrap      (const hal_flex_layout_param&);
        bool layout_cloumn          (const hal_flex_layout_param&);
        bool layout_cloumn_wrap     (const hal_flex_layout_param&);
        bool layout_cloumn_nowrap   (const hal_flex_layout_param&);

        // note: layout absolute
        bool layout_absolute        (const hal_flex_layout_param&, std::shared_ptr<hal_component_layout>&);

    private:
        std::weak_ptr<hal_component_layout> host_component_;

    protected:
        std::vector<hal_flex_layout_size> measure_cache_;
    };
}
#endif//Halberd_Kernal_Layout_Hal_Flex_H_
