cmake_minimum_required(VERSION 3.18)
project(UsefulModulesDemo)

add_executable(TestApp main.cpp)
target_include_directories(TestApp PRIVATE ${CMAKE_BINARY_DIR})

# include(CMakePrintHelpers)
# cmake_print_properties(TARGETS TestApp PROPERTIES INCLUDE_DIRECTORIES NAME SOURCES)

# set(my_awesome_var "that_keeps_great_value")
# cmake_print_variables(my_awesome_var)
# cmake_print_variables(CMAKE_CURRENT_LIST_FILE CMAKE_CXX_COMPILER)

# include(CMakeDependentOption)
# cmake_dependent_option(BUILD_TESTS "Build your tests" ON "VAL1;VAL2" OFF)
# # it's short hand for: if(VAL1 and VAL2) BUILD_TESTS=ON else BUILD_TESTS=OFF

# if(BUILD_TESTS)
#   # BUILD_TESTS is cached!! this means once set ON, will keep it's value
#   message("Building tests...")
# endif()

# include(CheckCXXCompilerFlag)
# # results of the checks are cached
# check_cxx_compiler_flag(-g is_g)
# check_cxx_compiler_flag(-b is_b)
# cmake_print_variables(is_g)
# cmake_print_variables(is_b)
