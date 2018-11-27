cmake_minimum_required(VERSION 3.12)
project(Project_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_5
        Assignment5.pdf
        maze.cpp
        maze.h
        recursion.cpp
        )
add_executable(main
        maze.cpp maze.h recursion.cpp)
