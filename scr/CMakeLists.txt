cmake_minimum_required(VERSION 3.14)
project(spinlock)

set(CMAKE_CXX_STANDARD 17)
add_executable(spinlock spinlock.hpp spinlock.cpp)
