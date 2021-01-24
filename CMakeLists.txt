cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
#包含文件
add_executable(untitled main.cpp arithmetic/arithmetic.cpp arithmetic/arithmetic.h my_selfString/my_selfString.h my_selfString/my_selfString.cpp head.h test.cpp)