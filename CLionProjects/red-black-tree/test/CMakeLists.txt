project(Lab_Tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests        
        lab10_tests.cpp
        )

add_subdirectory(gtest-1.7.0)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests
        lab10_lib
        )