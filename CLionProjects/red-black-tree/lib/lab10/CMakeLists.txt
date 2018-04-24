set(HEADER_FILES
        inc/red_black_tree.h)

set(SOURCE_FILES
        src/red_black_tree.cpp)
include_directories(inc)
add_library(lab10_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
