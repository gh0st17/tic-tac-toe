cmake_minimum_required(VERSION 3.0)
if(BUILD_TESTS)
  project(tictactoe-test)

  set(SOURCE_EXE main.cpp tests.cpp)
  add_executable(tictactoe-test ${SOURCE_EXE})
  target_link_libraries(tictactoe-test libGame libUI libPlayer)
endif()