cmake_minimum_required(VERSION 3.2)
project(LibrariesDemo)

# building and linking STATIC and SHARED libs
add_library(MathFunctions STATIC MathFunctions.cxx mysqrt.cxx)
add_executable(MyApp main.cpp)

# target_link_libraries(MyApp PRIVATE MathFunctions)
# target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")


# interface library example - common compile definitions
# add_library(MyCompileDefs INTERFACE)
# target_compile_definitions(MyCompileDefs INTERFACE "USE_MYMATH")
# target_link_libraries(MathFunctions PUBLIC MyCompileDefs)


# interface library example - header only library
# add_library(SciencePrinter INTERFACE)
# target_include_directories(SciencePrinter INTERFACE science_printer)
# target_link_libraries(MyApp PRIVATE SciencePrinter)

# next example if just theoretical - no code for this (you can implement one :P)
# interface library example - linking larger set of libraries
# if we more libs like:
# add_library(PhysicsFunctions STATIC PhysicsFunctions.cxx)
# add_library(ChemistryFunctions STATIC ChemistryFunctions.cxx)

# we can group them together with the MathFunctions:
# add_library(MyFunctions INTERFACE)
# target_link_libraries(MyFunctions INTERFACE MathFunctions PhysicsFunctions ChemistryFunctions)

# and then we can link them simply to apps by:
# target_link_libraries(MyApp PRIVATE MyFunctions)
