add_library(my_lib STATIC lib.cpp)
target_include_directories(my_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# return()
message("Testing debugging vars from lib dir.")
print_debug_vars()
