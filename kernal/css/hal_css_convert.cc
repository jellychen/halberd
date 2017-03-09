#include "hal_css_convert.h"
using namespace kernal;

bool hal_css_convert::convert(const char* str, int32_t* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }

    int data = 0;
    bool ret = 0 < ::sscanf(str, "%d", &data);
    *v = (int32_t)(data);
    return ret;
}

bool hal_css_convert::convert(const char* str, float* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }
    return 0 < ::sscanf(str, "%f", v);
}

bool hal_css_convert::convert(const char* str, double* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }
    return 0 < ::sscanf(str, "%lf", v);;
}

bool hal_css_convert::convert(const char* str, hal_color* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }
    return true;
}

bool hal_css_convert::convert(const char* str, hal_size* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }
    return true;
}

bool hal_css_convert::convert(const char* str, hal_divide* v) {
    if (nullptr == str || nullptr == v) {
        return false;
    }
    return true;
}
