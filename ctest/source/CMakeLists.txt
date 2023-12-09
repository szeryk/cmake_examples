cmake_minimum_required(VERSION 3.18)
project(CtestDemo)

# 1. define lib we want to test
add_library(myLib STATIC lib.cpp)

# 2. create a test exe that we will run in our test case
add_executable(myAddTests my_add_tests.cpp)
target_link_libraries(myAddTests PRIVATE myLib)

# 3. create a test case
enable_testing()
add_test(NAME addFunctionUnitTests COMMAND myAddTests)
# now ctest is available to use

# 4. set different pass/fail criteria
# set_tests_properties(addFunctionUnitTests PROPERTIES
    # PASS_REGULAR_EXPRESSION "Tests passed"
    # FAIL_REGULAR_EXPRESSION "Fail"
# )

# 5. add second test
# add_executable(myMultiplyTests my_multiply_tests.cpp)
# target_link_libraries(myMultiplyTests PRIVATE myLib)
# add_test(NAME multiplyFuncionUnitTests COMMAND myMultiplyTests)

# 6. add labels
# set_tests_properties(multiplyFuncionUnitTests PROPERTIES LABELS "multiply")
# set_tests_properties(addFunctionUnitTests PROPERTIES LABELS "add")

# 7. make the second test skipped if the first fails
# set_tests_properties(multiplyFuncionUnitTests PROPERTIES FIXTURES_REQUIRED Addition)
# set_tests_properties(addFunctionUnitTests PROPERTIES FIXTURES_SETUP Addition)


# 8. testing framework - in real world, we usually don't use custom test exes like the ones above
# Include(FetchContent)

# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        v3.4.0 # or a later release
# )

# FetchContent_MakeAvailable(Catch2)

# add_executable(catchTests catch_tests.cpp)
# target_link_libraries(catchTests PRIVATE Catch2::Catch2WithMain myLib)

# include(Catch)
# catch_discover_tests(catchTests)

# this last call makes each Cath TEST_CASE visible in ctest
# without we can see only combined result of whole file in ctest if we added it like:
# add_test(NAME allCatchTests COMMAND catchTests)
