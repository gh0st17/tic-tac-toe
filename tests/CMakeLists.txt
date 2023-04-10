cmake_minimum_required(VERSION 3.0)

if(BUILD_TESTS)
  project(tictactoe-test)

  set(SOURCE_EXE src/main.cpp)
  add_executable(tictactoe-test ${SOURCE_EXE})

  add_subdirectory(testlibs/libtestUI)
  add_subdirectory(testlibs/libtestAI)
  add_subdirectory(testlibs/libtestGame)

  target_link_libraries(tictactoe-test UI AI Error Game testUI testAI testGame)
endif()