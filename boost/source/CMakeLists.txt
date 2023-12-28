cmake_minimum_required(VERSION 3.24)
project(BoostDemo)

add_executable(TestApp main.cpp)

# this demo assumes boost was installed on the host with command like:
# sudo apt install libboost-all-dev
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem regex)

target_link_libraries(TestApp PRIVATE Boost::filesystem Boost::regex)