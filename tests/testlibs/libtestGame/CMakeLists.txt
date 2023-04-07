cmake_minimum_required(VERSION 3.0)

project(testGame)
set(SOURCE_LIB game_test.cpp)
add_library(testGame STATIC ${SOURCE_LIB})