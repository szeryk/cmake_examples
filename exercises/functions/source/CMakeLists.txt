cmake_minimum_required(VERSION 3.2)
project(IfsAndLoopsExercise)

# sum of all 
function(sum outVar)
    set(sumSoFar 0)
    foreach(i IN LISTS ARGN)
        math(EXPR sumSoFar "${sumSoFar} + ${i}")
    endforeach()
    set(${outVar} ${sumSoFar} PARENT_SCOPE)
endfunction(sum outVar)
sum(test 1 2 3 4 -5)
message("Sum: ${test}")

# generate exe
function(generateExe exeName sourceFile)
    string(TIMESTAMP time "%H-%M-%S")
    string(CONCAT finalName ${exeName} "_" ${time})
    add_executable(${finalName} ${sourceFile})
endfunction()
generateExe(test main.cpp)
generateExe(next_test main.cpp)
# fact: the time stamp is generated in GENERATION STEP, not build step!
