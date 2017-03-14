#ifndef Halberd_Kernal_Css_Hal_Css_Enum_H_
#define Halberd_Kernal_Css_Hal_Css_Enum_H_

#include "base/hal_inct.h"

namespace kernal {
    typedef enum {
        hal_css_postion_static                          ,
        hal_css_postion_relative                        ,
        hal_css_postion_absolute                        ,
        hal_css_postion_fixed                           ,
        hal_css_postion_auto = hal_css_postion_static   ,
    } hal_css_postion_t;

    typedef enum {
        hal_css_display_none                            ,
        hal_css_display_flex                            ,
        hal_css_display_auto = hal_css_display_flex     ,
    } hal_css_display_t;

    typedef enum {
        hal_css_flex_row                                ,
        hal_css_flex_column                             ,
        hal_css_flex_direction_auto = hal_css_flex_row  ,
    } hal_css_flex_direction_t;

    typedef enum {
        hal_css_flex_nowrap                             ,
        hal_css_flex_wrap                               ,
        hal_css_flex_wrap_auto = hal_css_flex_nowrap    ,
    } hal_css_flex_wrap_t;

    typedef enum {
        hal_css_flex_none                               ,
        hal_css_flex_start                              ,
        hal_css_flex_end                                ,
        hal_css_center                                  ,
        hal_css_space_between                           ,
        hal_css_space_around                            ,
        hal_css_space_stretch                           ,
        hal_css_flex_align_auto = hal_css_flex_start    ,
    } hal_css_flex_align_t;
}
#endif//Halberd_Kernal_Css_Hal_Css_Enum_H_
