cmake_minimum_required(VERSION 3.12)
project(Project_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        sequence3.cpp sequence3.h main.cpp)
add_executable(exam
        node1.h node1.cpp sequence3.cpp sequence3.h sequence3_exam.cpp)

