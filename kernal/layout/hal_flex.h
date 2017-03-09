#ifndef Halberd_Kernal_Layout_Hal_Flex_H_
#define Halberd_Kernal_Layout_Hal_Flex_H_

#include "base/hal_inct.h"
#include "utils/hal_t_define.h"

namespace kernal {

    class hal_component;
    class hal_flex final {
    public:
        hal_flex();
        hal_flex(std::shared_ptr<hal_component>&);
        virtual ~hal_flex();

    public:
        bool attach_component(std::shared_ptr<hal_component>&);

    public:
        bool measure();

    public:
        // note: layout children
        bool layout(const hal_rect&);

    private:
        // note: layout children
        bool layout_row(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_row_wrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_row_nowrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn_wrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn_nowrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_absolute(std::shared_ptr<hal_component>&, const hal_rect&);

    private:
        std::weak_ptr<hal_component> host_component_;
    };
}
#endif//Halberd_Kernal_Layout_Hal_Flex_H_
