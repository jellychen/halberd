#ifndef Halberd_Kernal_Layout_Hal_Flex_H_
#define Halberd_Kernal_Layout_Hal_Flex_H_

#include <base/hal_inct.h>
#include <dom/hal_component.h>

namespace kernal
{
    class hal_flex {
    public:
        hal_flex();
        virtual ~hal_flex();

    public:
        bool measure();

    public:
        // note: layout children
        bool layout(std::shared_ptr<hal_component>&, const hal_rect&);

        // note: layout param component
        bool layout_absolute(std::shared_ptr<hal_component>&, const hal_rect&);

    private:
        // note: layout children
        bool layout_row(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_row_wrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_row_nowrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn_wrap(std::shared_ptr<hal_component>&, const hal_rect&);
        bool layout_cloumn_nowrap(std::shared_ptr<hal_component>&, const hal_rect&);
    };
}
#endif//Halberd_Kernal_Layout_Hal_Flex_H_
