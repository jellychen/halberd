Project(webkernal)
CMake_Minimum_Required(VERSION 2.8)
Include_Directories("${PROJECT_SOURCE_DIR}")
Include_Directories("${PROJECT_SOURCE_DIR}/..")

Aux_Source_Directory(.                              srcs)
Aux_Source_Directory(./css                          srcs)
Aux_Source_Directory(./dom                          srcs)
Aux_Source_Directory(./event                        srcs)
Aux_Source_Directory(./html                         srcs)
Aux_Source_Directory(./layout                       srcs)
Aux_Source_Directory(./component                    srcs)
Aux_Source_Directory(./module                       srcs)
Aux_Source_Directory(./module/div                   srcs)
Aux_Source_Directory(./module/image                 srcs)
Aux_Source_Directory(./module/input                 srcs)
Aux_Source_Directory(./module/label                 srcs)
Aux_Source_Directory(./module/textarea              srcs)
Aux_Source_Directory(./render                       srcs)
Aux_Source_Directory(./render_al                    srcs)
Aux_Source_Directory(./render_al/canvas             srcs)
Aux_Source_Directory(./render_al/context            srcs)
Aux_Source_Directory(./render_al/path               srcs)
Aux_Source_Directory(./render_al/text               srcs)
Aux_Source_Directory(./render_al/texture            srcs)
Aux_Source_Directory(./render_al/transform          srcs)
Aux_Source_Directory(./render_recoder               srcs)
Aux_Source_Directory(./thread                       srcs)
Aux_Source_Directory(./io                           srcs)
Aux_Source_Directory(./io/http                      srcs)
Aux_Source_Directory(./io/local                     srcs)
Aux_Source_Directory(./io/cache                     srcs)
Aux_Source_Directory(./io/websocket                 srcs)
Aux_Source_Directory(./io/cache                     srcs)
Aux_Source_Directory(./isolate                      srcs)
Aux_Source_Directory(./utils                        srcs)

Include_Directories(
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../external"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/c"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/codec"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/config"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/core"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/effects"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/gpu"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/pathops"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/ports"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/private"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/svg"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/utils"
    "${PROJECT_SOURCE_DIR}/../external/skia/include/views"
)

Link_Directories(
    "${PROJECT_SOURCE_DIR}/../external/katana/build"
    "${PROJECT_SOURCE_DIR}/../external/gumbo/.libs"
    "${PROJECT_SOURCE_DIR}/../external/skia/out"
)

Add_Compile_Options(-std=c++11)
Add_Compile_Options(-Wnull-character)
Set(CMAKE_C_FLAGS  "-O2 -pipe -fPIC -Wall -fmessage-length=0 ${CMAKE_CXX_FLAGS}")
Set(CMAKE_CXX_FLAGS "-O2 -pipe -fPIC -Wall -fmessage-length=0 -fpermissive ${CMAKE_CXX_FLAGS}")
Add_Library(webkernal STATIC ${srcs})

Target_Link_Libraries(webkernal pthread gumbo katana skia)
Target_Link_Libraries(webkernal "-framework OpenGL")
Target_Link_Libraries(webkernal "-framework Foundation")
Target_Link_Libraries(webkernal "-framework CoreGraphics")
Target_Link_Libraries(webkernal "-framework QuartzCore")
Target_Link_Libraries(webkernal "-framework AppKit")
