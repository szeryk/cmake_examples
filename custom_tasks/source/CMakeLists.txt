cmake_minimum_required(VERSION 3.18)
project(CustomTasksDemo)

### CUSTOM TARGETS

# using exe as part of custom target
add_executable(HelloPrinter hello_printer.cpp)
add_custom_target(Custom1
    COMMAND HelloPrinter
)
# now make all and then make Custom1
# add ALL to see how it behaves


add_executable(Hasher hasher.cpp)
add_custom_target(Custom2
    COMMAND Hasher $<TARGET_FILE:HelloPrinter> # generator expression used here
)
# make Custom2, compare md5sums

### CUSTOM COMMANDS

# unlike custom target, will this be called each time HelloPrinter is changed
# no separate "make" needed
add_custom_command(TARGET HelloPrinter 
    POST_BUILD USES_TERMINAL
    COMMAND md5sum $<TARGET_FILE:HelloPrinter> > hash_from_custom_command.txt
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# generating files
add_executable(Generator generator.cpp)
# watch how on_the_fly.cpp here is generated relative to current binary dir
add_custom_command(OUTPUT on_the_fly.cpp
    COMMAND Generator
)
# on_the_fly.cpp privided with full path - if not, path relative to source dir is used
add_executable(OnTheFlyExe ${CMAKE_CURRENT_BINARY_DIR}/on_the_fly.cpp)
# will OnTheFlyExe be rebuilt if we change generator.cpp?
# DEPENDS generator.cpp needed in custom command

# generate from Python
add_custom_command(OUTPUT hello_world.cpp
    USES_TERMINAL
    COMMAND ./generator.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(GenHelloWorld
    DEPENDS ${CMAKE_BINARY_DIR}/hello_world.cpp
)
# custom targets are always out of date, so each call will generate new hello_world.cpp
