cmake_minimum_required( VERSION 3.12 )
project( Project1 )

set( CMAKE_CXX_STANDARD 14 )

add_executable( Project1 main.cpp barrel.cpp barrel.h test_barrel.h)