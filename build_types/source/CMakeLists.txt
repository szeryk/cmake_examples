cmake_minimum_required(VERSION 3.18)
project(BuildTypesDemo)

# set default build type
set(allowedBuildTypes Debug Release MinSizeRel RelWithDebInfo)
if(NOT CMAKE_BUILD_TYPE)
    #   var_name         Value CACHE Type  docs should_be_force?
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()
# to build with some other then Debug type:
# cmake -DCMAKE_BUILD_TYPE=Release ../source/

add_executable(TestApp main.cpp)


# how to influence the build types
message("Default C++ Debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message("Default C++ Release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message("Default C++ RelWithDebInfo flags: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message("Default C++ MinSizeRel flags: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

# 1. can edit one of those variables if want to change setting for the whole build
# look like the variable here is changed after the target is defined, but still it influences it!
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O2")
# message("Changed C++ Debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")

# 2. can prepare INTERFACE libs with proper compiler options
# add_library(OptimizedTargetFlags INTERFACE)
# target_compile_options(OptimizedTargetFlags INTERFACE "-O2")
# target_link_libraries(TestApp PRIVATE OptimizedTargetFlags)

# 3. can set flags to the dir (subdirs inherit those flags)
# look like this does not affect the first TestApp
# add_compile_options("-O2")
# add_executable(TestApp2 main.cpp)
