cmake_minimum_required(VERSION 3.18)
project(PresetsDemo)

add_executable(TestApp main.cpp)
add_executable(ExtraApp EXCLUDE_FROM_ALL extra_app.cpp)