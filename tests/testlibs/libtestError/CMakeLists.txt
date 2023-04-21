cmake_minimum_required(VERSION 3.0)

project(testError)
set(SOURCE_LIB error_test.cpp)
add_library(testError STATIC ${SOURCE_LIB})