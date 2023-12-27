cmake_minimum_required(VERSION 3.24)
project(CPMDemo)

add_executable(TestApp main.cpp)

# to download CPM cmake:
# mkdir -p cmake
# wget -O cmake/CPM.cmake https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake

# add CPM to the project:
include(cmake/CPM.cmake)

# there are different ways of adding packages, this is the shortest one
CPMAddPackage("gh:fmtlib/fmt#7.1.3")
CPMAddPackage("gh:nlohmann/json@3.10.5")

target_link_libraries(TestApp fmt::fmt nlohmann_json::nlohmann_json)

# by default packages are downlaoded per build dir
# but can be cached with env var: export CPM_SOURCE_CACHE=$HOME/.cache/CPM
