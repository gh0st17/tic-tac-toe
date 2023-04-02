cmake_minimum_required(VERSION 3.0)

project(libPlayer)
set(SOURCE_LIB Player.cpp)
add_library(libPlayer STATIC ${SOURCE_LIB})