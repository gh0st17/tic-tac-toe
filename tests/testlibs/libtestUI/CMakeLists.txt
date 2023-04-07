cmake_minimum_required(VERSION 3.0)

project(testUI)
set(SOURCE_LIB UI_test.cpp)
add_library(testUI STATIC ${SOURCE_LIB})