PROJECT(code_design)


cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)

message(STATUS " hahah ${CMAKE_SOURCE_DIR}")

set(SRC_PATH ${CMAKE_SOURCE_DIR}/code/src/)
set(MAIN_PATH ${CMAKE_SOURCE_DIR}/code/main/)

file(GLOB SRC ${SRC_PATH}/*.cpp /*.h)
message(STATUS "src:${SRC}")

file(GLOB MAIN ${MAIN_PATH}/*.cpp *.h)
message(STATUS "main:${MAIN}")

MESSAGE(STATUS "cpp: ${CMAKE_SOURCE_DIR}")

include_directories(
        ${PROJECT_NAME}/code/src
)

add_executable(code_design ${SRC} ${MAIN})

