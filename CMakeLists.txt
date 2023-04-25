cmake_minimum_required(VERSION 3.0)
project(tictactoe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_GENERATOR MATCHES "Visual Studio")
  set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -Wall")
  set(CMAKE_CXX_FLAGS_DEBUG
      "-O0 -g -fsanitize=address")
  set(CMAKE_CXX_FLAGS_RELEASE
      "-Ofast -flto=full -DNDEBUG")
else()
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} /Wall")
endif()

set(SOURCE_EXE src/main.cpp)
add_executable(tictactoe ${SOURCE_EXE})

add_subdirectory(libs/libUI)
add_subdirectory(libs/libAI)
add_subdirectory(libs/libError)
add_subdirectory(libs/libGame)
add_subdirectory(tests)

add_dependencies(tictactoe tictactoe-test)

target_link_libraries(tictactoe UI AI Error Game)