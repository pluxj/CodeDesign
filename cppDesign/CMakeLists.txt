PROJECT(code_design)


cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

include_directories(./code/src/)

add_subdirectory(test/test_command)
add_subdirectory(test/test_decorator)
add_subdirectory(test/test_observer)
add_subdirectory(test/test_state)


