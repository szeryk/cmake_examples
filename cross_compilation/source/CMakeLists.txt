cmake_minimum_required(VERSION 3.24)
project(CrossCompiletionDemo)

add_executable(TestApp main.cpp)

# to build this app for Rasberry Pi 3:
# https://github.com/tttapa/docker-arm-cross-toolchain?tab=readme-ov-file#installation
# and then just call cmake with --toolchain ~/path/to/aarch64-rpi3-linux-gnu.toolchain.cmake
# and now you can build the project with "make"