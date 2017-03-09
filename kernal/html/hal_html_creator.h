#ifndef Halberd_Kernal_Html_Hal_Html_Creator_H_
#define Halberd_Kernal_Html_Hal_Html_Creator_H_

#include <base/hal_inct.h>

#include <dom/hal_element.h>
#include <component/hal_component.h>

namespace kernal {
    class hal_html_creator final {
    public:
        // create element but not whole dom
        // arguments like <div><h1>...</h1></div>

        std::shared_ptr<hal_element> create_element_from_file(
            std::shared_ptr<hal_document>& doc, const char* file);
        std::shared_ptr<hal_element> create_element_from_buffer(
            std::shared_ptr<hal_document>& doc, const char* buffer, size_t size);

    public:
        // these function will clear document head and body
        // arguments like
        // <html>
        // <head></head>...<body></body>
        // </html>
        // parser out will be setup into document
        // the origin info in document will be erase

        bool build_dom_from_file(std::shared_ptr<hal_document>& doc, const char* file);
        bool build_dom_from_buffer(std::shared_ptr<hal_document>& doc, const char* buffer, size_t size);
    };
}
#endif//Halberd_Kernal_Html_Hal_Html_Creator_H_
