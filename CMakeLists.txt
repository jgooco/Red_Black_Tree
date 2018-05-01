cmake_minimum_required(VERSION 3.9)
project(Red_Black_Tree)

if(WIN32)
    if (CYGWIN)
        add_definitions(-std=gnu++0x)
    elseif(MINGW)
        add_definitions(-std=c++11)
    endif (CYGWIN)
endif(WIN32)
if(APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif(APPLE)
if(UNIX)
    add_definitions(-std=gnu++0x)
endif(UNIX)


set(SOURCE_FILES CLionProjects/Red-Black-Tree/main.cpp)

add_executable(labs_main ${SOURCE_FILES})

include_directories(CLionProjects/Red-Black-Tree/lib/lab10/inc

        )

add_subdirectory(CLionProjects/Red-Black-Tree/lib/lab10 lab10_lib)

add_subdirectory(CLionProjects/Red-Black-Tree/test)

target_link_libraries(labs_main
        lab10_lib
        )