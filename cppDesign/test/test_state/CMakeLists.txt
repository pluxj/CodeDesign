PROJECT(test_state)


cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)
aux_source_directory(. DIR_LIB_SRCS)
aux_source_directory(../../code/src SRC)
add_executable(${PROJECT_NAME} ${DIR_LIB_SRCS} ${SRC})



