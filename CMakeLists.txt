cmake_minimum_required(VERSION 3.0)
project(tictactoe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE
    Release
    CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS
    "-Wall"
    CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG
    "-O0 -g -fsanitize=address"
    CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE
    "-Ofast -flto=full -DNDEBUG"
    CACHE STRING "" FORCE)
    
option(BUILD_TESTS "Set to ON to build tests" OFF)

set(SOURCE_EXE src/main.cpp)
add_executable(tictactoe ${SOURCE_EXE})

add_subdirectory(libs/libUI)
add_subdirectory(libs/libPlayer)
add_subdirectory(libs/libGame)

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()

target_link_libraries(tictactoe UI Player Game)