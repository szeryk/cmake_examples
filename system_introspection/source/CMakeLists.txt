cmake_minimum_required(VERSION 3.18)
project(SystemIntrospectionDemo)

add_executable(TestApp main.cpp)

# collect many queries into a list
cmake_host_system_information(RESULT host_info QUERY 
    OS_NAME 
    PROCESSOR_NAME 
    NUMBER_OF_LOGICAL_CORES 
    HOSTNAME
)
message("Host info: ${host_info}")

# check if some function is available
include(CheckCXXSourceCompiles)

# remember that result of this call is cached!
# check_cxx_source_compiles("
#     #include <cmath>
#     int main() {
#       std::log(1.0);
#       return 0;
#     }
# " HAVE_LOG)

# message("Have log? ${HAVE_LOG}")
# if(HAVE_LOG)
#     target_compile_definitions(TestApp PRIVATE "HAVE_LOG")
# endif()

# how to create "configure file"
# cmake_host_system_information(RESULT OS_NAME QUERY OS_NAME)
# cmake_host_system_information(RESULT HOST_NAME QUERY HOSTNAME)
# configure_file(host_info.h.in host_info.h)
# target_include_directories(TestApp PRIVATE ${CMAKE_BINARY_DIR})
