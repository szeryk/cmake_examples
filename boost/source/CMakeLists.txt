cmake_minimum_required(VERSION 3.24)
project(BoostDemo)

add_executable(TestApp main.cpp)

# this demo assumes boost was installed on the host with command like:
# sudo apt install libboost-all-dev
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem regex)

target_link_libraries(TestApp PRIVATE Boost::filesystem Boost::regex)

# it's possible to fetch and build Boost instead of using find package:
# warning -> downloading boost takes time...
# set(BOOST_INCLUDE_LIBRARIES filesystem regex)
# set(BOOST_ENABLE_CMAKE ON)
# include(FetchContent)
# FetchContent_Declare(
#   Boost
#   GIT_REPOSITORY https://github.com/boostorg/boost.git
#   GIT_TAG boost-1.80.0
# )
# FetchContent_MakeAvailable(Boost)
