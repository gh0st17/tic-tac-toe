cmake_minimum_required(VERSION 3.0)

project(tictactoe-test)

set(SOURCE_EXE src/main.cpp)
add_executable(tictactoe-test ${SOURCE_EXE})

add_subdirectory(testlibs/libtestUI)
add_subdirectory(testlibs/libtestAI)
add_subdirectory(testlibs/libtestGame)

target_link_libraries(tictactoe-test UI AI Error Game testUI testAI testGame)

add_custom_command(TARGET tictactoe-test POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running tests..."
)

file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})