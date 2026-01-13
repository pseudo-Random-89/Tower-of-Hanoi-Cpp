cmake_minimum_required(VERSION 4.1)
project(Programs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Programs
        algorithm.cpp
        toh.cpp
        toh.hpp
        solver.cpp
        solver.hpp
)
