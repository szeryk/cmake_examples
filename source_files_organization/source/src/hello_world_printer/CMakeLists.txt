add_library(HelloWorldPrinter STATIC hello_world_printer.cpp)
target_include_directories(HelloWorldPrinter PUBLIC ${CMAKE_SOURCE_DIR}/include)

# print_debug_vars()
