#ifndef Halberd_Kernal_Render_Al_Hal_Render_Require_H_
#define Halberd_Kernal_Render_Al_Hal_Render_Require_H_

// skia header file
#include "SkData.h"
#include "SkImage.h"
#include "SkStream.h"
#include "SkSurface.h"
#include "SkPaint.h"
#include "SkScalar.h"
#include "SkPoint3.h"
#include "SkTypes.h"
#include "SkCanvas.h"
#include "SkFont.h"
#include "SkBitmap.h"
#include "SkCodec.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkCamera.h"
#include "SkTypeface.h"

// gl
#include "GrContext.h"
#include "gl/GrGLInterface.h"

// type
#include "utils/hal_t_define.h"

namespace kernal {

    inline SkRect __convert_to_t(const hal_rect& rect) {
        float x = rect.x_, y = rect.y_;
        float r = x +  rect.width_, b = y + rect.height_;
        SkRect _rect; _rect.set(x, y, r, b); return _rect;
    }

    inline SkPoint __convert_to_t(const hal_point& point) {
        SkPoint _point; _point.set(point.x_, point.y_); return _point;
    }
}
#endif//Halberd_Kernal_Render_Al_Hal_Render_Require_H_
