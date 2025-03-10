cmake_minimum_required(VERSION 3.30)
project(cppEdu)

set(CMAKE_CXX_STANDARD 23)
SET(CMAKE_BUILD_TYPE Debug)
add_executable(edu Templating/STL_Pseudo_Implementations/main.cpp)

add_subdirectory(helperlib)

target_link_libraries(edu PUBLIC helperlib)
target_include_directories(edu PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/helperlib")


#find_package(GTest CONFIG REQUIRED)
#target_link_libraries(edu GTest::gtest GTest::gtest_main)
