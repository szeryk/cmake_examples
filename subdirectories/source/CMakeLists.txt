cmake_minimum_required(VERSION 3.18)
project(SubdirectoriesDemo)

include(cmake/print_debug_vars.cmake)

add_subdirectory(app)
add_subdirectory(lib)
