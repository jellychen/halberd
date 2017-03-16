#include <functional>
#include <iostream>
using namespace std;

#include <kernal/dom/hal_document.h>
#include <kernal/component/hal_component_creator.h>
#include <kernal/html/hal_html_creator.h>
#include <kernal/render_al/hal_render_inct.h>
#include <kernal/utils/hal_file_read.h>
#include <kernal/render_al/text/hal_render_text_attr.h>
#include <kernal/thread/hal_thread_instance.h>
#include <kernal/render_recoder/hal_render_recoder_inct.h>
#include <kernal/isolate/hal_isolate.h>
#include <kernal/utils/hal_current_time.h>

#include <kernal/dom/hal_document_area_index.h>

#include "thread.h"

#include "mac/mac_test.h"

using namespace kernal;

class c {
public:
    c(int i ) {
        printf("%s\n", "c");
    }
};

class b{
public:
    b() {
        printf("%s\n", "b");
    }
    virtual ~b(){
        printf("%s\n", "~b");
    }
};

class a {
public:


    a(){
        //printf("%s\n", "a");
    }
/*
    a(const a&) {
        printf("%s\n", "c a");
    }

    virtual ~a() {
        printf("%s\n", "~a");
    }

    void get() const {
        printf("%s\n", "guodong");
    }

    a& operator=(const a&) {
        printf("%s\n", "a operator=");
        return *this;
    }

    a& operator=(const a&&) {
        printf("%s\n", "a operator==");
        return *this;
    }*/
};

int main()
{

    hal_isolate isolate_; isolate_.init();
    int data = 0; std::cin >> data; return 0;




    {
        auto root = std::shared_ptr<hal_component_render>(new hal_component_render());
        for (int i = 0; i < 100000; ++i) {
            auto render = std::shared_ptr<hal_component_render>(new hal_component_render());
            auto ele = std::dynamic_pointer_cast<hal_element>(render);
            root->append_child(ele);
        }

        hal_current_time timer__;
        for (uint32_t i = 0; i < 100000; ++i) {
            auto ele = root->at(i);
            auto render = std::dynamic_pointer_cast<hal_component_render>(ele);
        }
        printf("%lld  %d\n", timer__.elapsed(), 0);
    }
    return 0;


    auto doc = hal_creator<hal_document>::instance();
    hal_html_creator creator;
    auto ele = creator.build_dom_from_file(doc, "/test/1.html");
    printf("%d\n", doc->id_index_.count());

    std::string utf8_data;
    hal_file_read::read_whole("/test/2.txt", utf8_data);




    //return 0;


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
/*
    for (int i = 0; i < 1000; ++i) {
        printf("++ %d\n", i);
        //auto _thread = hal_creator<hal_thread_instance>::instance();
        std::shared_ptr<hal_thread_instance> _t (new hal_thread_instance());
    }
*/



    std::shared_ptr<hal_render_surface_canvas> surface_canvas
        = hal_creator<hal_render_surface_canvas>::instance(hal_size_make(1080, 1920));
    auto base_canvas1 = std::dynamic_pointer_cast<hal_render_canvas>(surface_canvas);

    std::shared_ptr<hal_render_mem_canvas> mem_canvas
        = hal_creator<hal_render_mem_canvas>::instance(hal_size_make(1080, 1920));
    auto base_canvas2 = std::dynamic_pointer_cast<hal_render_canvas>(mem_canvas);

    std::shared_ptr<hal_render_context> context
        = hal_creator<hal_render_context>::instance(base_canvas2);

hal_current_time timer__;

    context->erase(hal_color_make(255,255,255,255));


    auto r_buffer = hal_creator<hal_render_command_buffer>::instance(false);

    {



        auto c_context = hal_creator<hal_render_command_context>::instance(r_buffer);
        c_context->draw_round_rect(hal_rect_make(10, 10, 200, 200), 30, 30, 5, hal_color_make(255,0,0,255), 1);

        c_context->save_state();
        c_context->clip_intersect(hal_rect_make(10, 10, 150, 150), 1);

        c_context->begin_path();
        c_context->move_to(hal_point_make(0, 0));
        c_context->line_to(hal_point_make(100, 100));
        c_context->close_path();

        c_context->stroke_path(hal_color_make(44,0,0,255), 10, 1);
        c_context->clear_path();
        c_context->restore_state();

        auto c_texture = hal_creator<hal_render_command_texture>::instance(r_buffer);
        c_texture->load_file("/test/1.jpg");
        c_texture->draw(200, true, 0, 0);


        auto c_text = hal_creator<hal_render_command_text>::instance(r_buffer);
        c_text->text_attr_.text_size_ = 30;
        c_text->text_attr_.aa_ = 1;
        c_text->draw_oneline("guodong", 7, hal_point_make(10, 10), hal_color_make(0,0,0,255), 200);
        c_text->draw_multiLine(utf8_data.c_str(), utf8_data.size(), hal_rect_make(0,0, 100, 100), 4, hal_point_make(0, 0), hal_color_make(0,0,0,255), 255);

    }


    r_buffer->run(context);

printf("%lld\n", timer__.elapsed());

/*

    context->draw_line(
        hal_point_make(0,0),
        hal_point_make(50,0), 1, hal_color_make(255,0,0,255), 1);
        //context->draw_round_rect(hal_rect_make(10, 10, 200, 200), 30, 30, 5, hal_color_make(255,0,0,255), 1);

    auto _font = std::shared_ptr<hal_render_text_font>(new hal_render_text_font());
    const char* data = "12312果冻odauosduaiosduioa"; uint32_t len = strlen(data);
    hal_render_text_attr text;
    text.font_ = _font;
    text.font_->make_bold_italic("STHeiti");
    text.aa_ = 1; text.text_size_ = 13; //text.under_line_ = 1; text.strike_line_ = 1;
    text.draw_oneline(context, utf8_data.c_str(), utf8_data.size(), hal_point_make(0, 0), hal_color_make(0,0,0,255));
    //text.draw_multiLine(context, utf8_data.c_str(), utf8_data.size(), hal_rect_make(0,0, 100, 100), 4, hal_point_make(0, 0), hal_color_make(0,0,0,255));
*/

    context->capture_to_file("1.png");


/*

*/



    return 0;
}
