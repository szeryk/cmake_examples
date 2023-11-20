cmake_minimum_required(VERSION 3.2)
project(ModulesDemo)

# custom modules demo
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# make functions from module available
include(MyModule)

# other option - CMAKE_MODULE_PATH not needed then
include(cmake/OtherModule.cmake)

my_function()
other_function()




# built-in modules demo
include(CheckSourceCompiles)
check_source_compiles(CXX "int main() { int myVar; }" compilationStatus)
message("Compilation status: ${compilationStatus}")
# try to change the source code to faulty one and re-run cmake
