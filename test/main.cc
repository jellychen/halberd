#include <functional>
#include <iostream>
using namespace std;

#include <kernal/dom/hal_document.h>
#include <kernal/dom/hal_component_creator.h>
#include <kernal/html/hal_html_creator.h>
#include <kernal/render_al/hal_render_inct.h>

#include <kernal/render_al/text/hal_render_text_attr.h>
#include <kernal/thread/hal_thread_instance.h>

#include "mac/mac_test.h"

using namespace kernal;


class a {
public:
    a(){

    }

    void get() {
        printf("%s\n", "guodong");
    }
};

int main()
{

    auto doc = hal_creator<hal_document>::instance();
    hal_html_creator creator;
    auto ele = creator.build_dom_from_file(doc, "/test/1.html");

    printf("%d\n", doc->id_index_.count());

    return 0;


    /*
    for (int i = 0; i < 100000; ++i) {
        const char* data = "极";
        hal_render_text_attr text_attr_;
        hal_size _size = {0, 0};
        text_attr_.measure_size(data, strlen(data), &_size);
    }
    //printf("%f %f\n", _size.width_, _size.height_);

    return 0;
    */

    for (int i = 0; i < 0; ++i) {
        printf("++ %d\n", i);
        //auto _thread = hal_creator<hal_thread_instance>::instance();
        std::shared_ptr<hal_thread_instance> _t (new hal_thread_instance());
    }


printf("%s\n", "1");


    std::shared_ptr<hal_render_canvas> canvas
        = hal_creator<hal_render_canvas>::instance(hal_size_make(1000, 1000));
    std::shared_ptr<hal_render_canvas> s = canvas;
    std::shared_ptr<hal_render_context> context
        = hal_creator<hal_render_context>::instance(canvas);




    context->draw_line(
        hal_point_make(0,0),
        hal_point_make(50,50), 3, hal_color_make(255,0,0,255), 1);



    context->draw_round_rect(hal_rect_make(10, 10, 200, 200), 30, 30, 5, hal_color_make(255,0,0,255), 1);
    context->capture_to_file("1.png");


/*

*/



    return 0;
}
