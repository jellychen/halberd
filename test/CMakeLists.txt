Project(test)
CMake_Minimum_Required(VERSION 2.8)
Add_Compile_Options(-std=c++11)
Include_Directories("${PROJECT_SOURCE_DIR}")
Include_Directories("${PROJECT_SOURCE_DIR}/..")

Include_Directories(
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../kernal"
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

Aux_Source_Directory(.          srcs)
Aux_Source_Directory(./mac      srcs)

Add_Executable(test ${srcs})
Set(CMAKE_CXX_FLAGS "-fpermissive ${CMAKE_CXX_FLAGS}")
Target_Link_Libraries(test webkernal)
Target_Link_Libraries(test "-framework Cocoa")
