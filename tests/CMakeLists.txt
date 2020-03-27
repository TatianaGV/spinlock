cmake_minimum_required(VERSION 3.14)
project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(tests tests.cpp spinlock.hpp spinlock.cpp)

target_link_libraries(tests gtest gtest_main pthread)

gtest_add_tests(
        TARGET tests
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
)