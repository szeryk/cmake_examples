cmake_minimum_required(VERSION 3.2)
project(IfsDemo)

# basic expression form:
# if(expression1)
  # ...
# elseif(expression2)
  # ...
# else()
  # ...
# endif()

if(YES)
    message("YES means true!")
endif()

if(0)
    message("0 means true!")
else()
    message("0 means false!")
endif()

set(A YES)
if(A) # string matching defined variable -> variable value is used here
    message("Var A contains true!")
endif()
if(${A}) # unquoted YES is here, as variable is expanded before call to if()
    message("Var A contains true again!")
endif()

if(undefined_variable_name)
    message("undefined variable evaluates to true!")
else()
    message("undefined variable evaluates to false!")
endif()

# string different than any YES-like string -> false
# at least in CMake 3.1+. For older, it would still try first to look for variable with
# the same name as string value...
if("A") 
    message("Some string that is not YES-like is true!")
else()
    message("Some string that is not YES-like is false!")
endif()

# undefined behavior (depends on CMake version)
if("21p" EQUAL 21)
    message("Undefined behavior hits true!")
endif()

# some logic challenge here
# set(myName Eryk)
# if(7 GREATER 1)
#     if ("33" EQUAL 33)
#         if(1.8.2 VERSION_LESS 2.0)
#             message("Answer A")
#         else()
#             message("Answer B")
#         endif()
#     elseif("My name is ${myName}" MATCHES "My name is (Bond|JamesBond).*")
#         message("Answer C")
#     else()
#         message("Answer D")
#     endif()
# elseif(DEFINED myName)
#     message("Answer E")
# endif()




