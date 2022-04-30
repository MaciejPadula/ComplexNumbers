cmake_minimum_required(VERSION 3.20)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ComplexNumbers
        complex.cpp
        complex.h
        main.cpp)
