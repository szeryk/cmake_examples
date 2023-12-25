cmake_minimum_required(VERSION 3.24)
project(SuperBuildDemo)

add_executable(TestApp main.cpp)
include(ExternalProject)

### OPENSSL EXAMPLE
# I don't want to install sub projects in my OS default locations
# but rather in my build dir for this superbuild
# set(OPENSSL_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/openssl-src) # default path by CMake
# set(OPENSSL_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/openssl)
# set(OPENSSL_INCLUDE_DIR ${OPENSSL_INSTALL_DIR}/include)
# set(OPENSSL_CONFIGURE_COMMAND ${OPENSSL_SOURCE_DIR}/config)

# include(ExternalProject)
# ExternalProject_Add(
#   OpenSSL
#   SOURCE_DIR ${OPENSSL_SOURCE_DIR}
#   GIT_REPOSITORY https://github.com/openssl/openssl.git
#   GIT_TAG OpenSSL_1_1_1n
#   USES_TERMINAL_DOWNLOAD TRUE
#   CONFIGURE_COMMAND
#     ${OPENSSL_CONFIGURE_COMMAND}
#     --prefix=${OPENSSL_INSTALL_DIR}
#     --openssldir=${OPENSSL_INSTALL_DIR}
#   BUILD_COMMAND make
#   TEST_COMMAND ""
#   INSTALL_COMMAND make install
#   INSTALL_DIR ${OPENSSL_INSTALL_DIR}
# )

### SHA256 EXAMPLE
ExternalProject_Add(sha256
  GIT_REPOSITORY https://github.com/System-Glitch/SHA256.git
  GIT_TAG origin/master
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/sha256-prefix/src/sha256-build/sha256-example
        ${CMAKE_BINARY_DIR}/sha256
)

### FMT EXAMPLE
set(fmt_install_prefix ${CMAKE_BINARY_DIR}/install)
ExternalProject_Add(
    fmt
    PREFIX ${CMAKE_BINARY_DIR}/fmt
    # GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    # GIT_TAG origin/master
    URL https://github.com/fmtlib/fmt/releases/download/10.1.1/fmt-10.1.1.zip
    CMAKE_ARGS -DFMT_TEST=OFF -DCMAKE_INSTALL_PREFIX=${fmt_install_prefix}
    BUILD_COMMAND ${CMAKE_COMMAND} --build . --target install
)

# Include the fmt headers and link to the library
target_include_directories(TestApp PRIVATE ${fmt_install_prefix}/include)
target_link_libraries(TestApp PRIVATE ${fmt_install_prefix}/lib/libfmt.a)
add_dependencies(TestApp fmt)

