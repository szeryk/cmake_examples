cmake_minimum_required(VERSION 3.18)
project(SourceFilesOrganizationDemo)

include(cmake/print_debug_vars.cmake)

add_subdirectory(apps)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)