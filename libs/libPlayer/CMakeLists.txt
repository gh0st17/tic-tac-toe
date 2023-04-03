cmake_minimum_required(VERSION 3.0)

project(Player)
set(SOURCE_LIB Player.cpp)
add_library(Player STATIC ${SOURCE_LIB})