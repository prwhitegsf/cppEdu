cmake_minimum_required(VERSION 3.30)
project(cppEdu)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_BUILD_TYPE Debug)
add_executable(edu Templating/Printer/main.cpp)

include_directories(helperlib)
add_subdirectory(helperlib)
target_link_libraries(edu helperlib)

#find_package(GTest CONFIG REQUIRED)
#target_link_libraries(edu GTest::gtest GTest::gtest_main)
