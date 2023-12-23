# Preamble
cmake_minimum_required(VERSION 3.18)
project(SourceFilesOrganizationDemo)
enable_testing()

# Project wide setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# modules / external content
include(cmake/print_debug_vars.cmake)

# main targets
add_subdirectory(apps)
add_subdirectory(src)

# testing
add_subdirectory(tests)

# possibly packaging goes here at the end
