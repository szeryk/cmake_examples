cmake_minimum_required(VERSION 3.18)
project(InstallDemo)

add_library(MyLib SHARED my_lib/my_lib.cpp)
target_include_directories(MyLib PUBLIC my_lib)

add_executable(MyApp my_app.cpp)
target_link_libraries(MyApp PRIVATE MyLib)

# CMake default values are pretty similar to GNUInstallDirs
# but the module handles better different Linux distros
include(GNUInstallDirs)

message("install PREFIX: ${CMAKE_INSTALL_PREFIX}")
# those below are defined by GNUInstallDirs
message("install RUNTIME dir: ${CMAKE_INSTALL_BINDIR}")
message("install LIBRARY dir: ${CMAKE_INSTALL_LIBDIR}")
message("install HEADERS dir: ${CMAKE_INSTALL_INCLUDEDIR}")

install(TARGETS MyApp MyLib
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# make install - if lib cannot be found, maybe just need to:
# sudo ldconfig
# to refresh the list of shared libs

# BONUS: if you ever need to install headers
# target_sources(
#   mylib
#   PUBLIC
#     FILE_SET public-headers # -> this is available from CMake 3.23
#     TYPE HEADERS
#     FILES
#       myfirstpublicheader.h
#       mysecondpublicheader.h
# )
# install(TARGETS mylib FILE_SET public-headers)

