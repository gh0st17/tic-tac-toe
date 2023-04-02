cmake_minimum_required(VERSION 3.0)
project(tictactoe)

set(SOURCE_EXE src/main.cpp)

include_directories(libs/libGame libs/libUI libs/libPlayer tests)

option(BUILD_TESTS "Set to ON to build tests" OFF)

add_executable(tictactoe ${SOURCE_EXE})

add_subdirectory(libs/libGame)
add_subdirectory(libs/libUI)
add_subdirectory(libs/libPlayer)
add_subdirectory(tests)

target_link_libraries(tictactoe libGame libUI libPlayer)