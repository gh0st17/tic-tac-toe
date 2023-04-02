cmake_minimum_required(VERSION 3.0)

project(libUI)
set(SOURCE_LIB UI.cpp)
add_library(libUI STATIC ${SOURCE_LIB})