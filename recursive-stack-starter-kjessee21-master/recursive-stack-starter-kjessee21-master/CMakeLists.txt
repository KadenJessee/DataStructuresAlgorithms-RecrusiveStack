cmake_minimum_required(VERSION 3.14)
project(stacks)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(stacks
        inc/Stack.h
        inc/ParenthesesMatch.h
        src/ParenthesesMatch.cpp
        src/StackTest.cpp)
