cmake_minimum_required(VERSION 3.24)
project(ConanDemo)

add_executable(TestApp main.cpp)

# to enable Conan in CMake, first call to CMake should have this vars:
# -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=/home/eryk/repos/cmake-conan/conan_provider.cmake 
# -DCMAKE_BUILD_TYPE=Debug

# find package will find Conan packages
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(TestApp PRIVATE fmt::fmt nlohmann_json::nlohmann_json)
