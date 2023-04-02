cmake_minimum_required(VERSION 3.0)

project(libGame)
set(SOURCE_LIB Game.cpp)
add_library(libGame STATIC ${SOURCE_LIB})