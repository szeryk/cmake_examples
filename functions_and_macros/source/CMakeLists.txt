cmake_minimum_required(VERSION 3.25)
project(FunctionsAndMacrosDemo)

# functions vs macros - biggest difference
function(fun arg1)
    if(DEFINED arg1)
        message("Function has defined arg1 with value: ${arg1}") 
    else()
        message("Function has not defined arg1 with value: ${arg1}") 
    endif()
endfunction()

macro(mac arg1)
     if(DEFINED arg1)
        message("Macro has defined arg1 with value: ${arg1}") 
    else()
        message("Macro has not defined arg1 with value: ${arg1}") 
    endif()
endmacro()

fun("Eryk")
mac("Eryk")
message("")

# argument handling example
function(fun2 namedArg)
    message("Named arg value: ${namedArg}")
    message("Unnamed args list: ${ARGN}")
    message("First arg value: ${ARGV0}")
    message("Second unnamed arg value: ${ARGN1}") # doesn't work like ARGV? :(
endfunction()
fun2("test" "some" "other" "args")
message("")

# arg parse example
function(fun3)
    set(options OPTIONAL FAST)
    set(oneValueArgs DESTINATION RENAME)
    set(multiValueArgs TARGETS CONFIGURATIONS)
    cmake_parse_arguments(FUN3 "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN} )
    message("FUN3_OPTIONAL=${FUN3_OPTIONAL}")
    message("FUN3_FAST=${FUN3_FAST}")
    message("FUN3_DESTINATION=${FUN3_DESTINATION}")
    message("FUN3_RENAME=${FUN3_RENAME}")
    message("FUN3_TARGETS=${FUN3_TARGETS}")
    message("FUN3_CONFIGURATIONS=${FUN3_CONFIGURATIONS}")
    message("FUN3_UNPARSED_ARGUMENTS=${FUN3_UNPARSED_ARGUMENTS}")
    message("FUN3_KEYWORDS_MISSING_VALUES=${FUN3_KEYWORDS_MISSING_VALUES}")
endfunction()

fun3(TARGETS foo bar DESTINATION bin OPTIONAL blub CONFIGURATIONS)
message("")

# returning values
function(fun4 outVar)
    set(${outVar} "fun4 value" PARENT_SCOPE) # value of outVar is the name of out var in parent scope
endfunction()
fun4(someVar)
message("Dir scopes sees: ${someVar}")

macro(mac2 outVar)
    set(${outVar} "mac2 value") # value of mac2OutVar is the name of out var in parent scope
endmacro()
mac2(someVar)
message("Dir scopes sees: ${someVar}")

function(fun5 outVar)
    set(${outVar} "fun5 value")
    return(PROPAGATE ${outVar})
endfunction()
fun5(someVar)
message("Dir scopes sees: ${someVar}")
message("")

# debugging
function(debugging)
    message("Function name: ${CMAKE_CURRENT_FUNCTION}")
    message("Function file: ${CMAKE_CURRENT_FUNCTION_LIST_FILE}")
    message("Function file folder: ${CMAKE_CURRENT_FUNCTION_LIST_DIR}")
    message("Function defined at line: ${CMAKE_CURRENT_FUNCTION_LIST_LINE}")
endfunction()
debugging()


