cmake_minimum_required(VERSION 3.24)
project(GTestDemo)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library to be tested
add_library(myLib STATIC lib.cpp)

# fetch the google test framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)


enable_testing()

# prepare some example gtest test cases
add_executable(ExampleTests example_tests.cpp)
target_link_libraries(ExampleTests GTest::gtest_main)

# prepare tests for myLib
add_executable(myLibTests lib_tests.cpp)
target_link_libraries(myLibTests myLib GTest::gtest_main)

include(GoogleTest) # this is a CMake built-in module
gtest_discover_tests(ExampleTests)
gtest_discover_tests(myLibTests)
