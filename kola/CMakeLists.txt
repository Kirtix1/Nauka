cmake_minimum_required(VERSION 3.27)
project(figury1)

set(CMAKE_CXX_STANDARD 17)

add_executable(figury1 main.cpp
        cmake-build-debug/figury.h
        cmake-build-debug/figury.cpp)
