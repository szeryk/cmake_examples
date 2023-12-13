cmake_minimum_required(VERSION 3.18)
project(DoxygenDemo)

include(cmake/enable_doxygen.cmake)
enable_doxygen()

add_executable(TestApp main.cpp)
