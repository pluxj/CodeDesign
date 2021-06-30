PROJECT(test_command)


cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)
aux_source_directory(. DIR_LIB_SRCS)
add_executable(${PROJECT_NAME} ${DIR_LIB_SRCS})



