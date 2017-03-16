#ifndef Halberd_Kernal_Ioslate_Hal_Isolate_Bundle_H_
#define Halberd_Kernal_Ioslate_Hal_Isolate_Bundle_H_

#include "base/hal_inct.h"

namespace kernal {
    class hal_isolate;
    class hal_isolate_bundle final {
    public:
        hal_isolate_bundle();
        virtual ~hal_isolate_bundle();

    public:
        // note: resize document view port
        bool resize_view(hal_size& size);

        // note: load from network
        bool load_url(const char* url);

        // note: load from file system
        bool load_from_file(const char* name);

        // note: capture canvas file
        bool capture_canvas_to_file(const char* name);

    private:
        std::shared_ptr<hal_isolate> isolate_kernal_;
    };
}
#endif//Halberd_Kernal_Ioslate_Hal_Isolate_Bundle_H_
