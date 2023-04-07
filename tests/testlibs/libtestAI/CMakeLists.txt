cmake_minimum_required(VERSION 3.0)

project(testAI)
set(SOURCE_LIB AI_test.cpp)
add_library(testAI STATIC ${SOURCE_LIB})