cmake_minimum_required(VERSION 3.22)
project(GeneratorExpressionsDemo)

set(test1 $<1:foo>)
set(test2 $<0:foo>)
set(test3 $<true:foor>)
set(test3 $<$<BOOL:true>:foo>)
set(test4 $<$<NOT:0>:foo>)
set(test5 $<$<NOT:true>:foo>)
set(test6 $<$<AND:1,0>:foo>)
set(test7 $<1:$<$<BOOL:false>:foo>>)
set(test8 $<IF:$<BOOL:ON>,yes,no>)
set(test9 $<PLATFORM_ID>)

# it's not possible to debug generator expressions with message()
# as they are evaluated in generation step and message() is printed
# during configuration step
add_custom_target(genexdebug 
    COMMAND ${CMAKE_COMMAND} -E echo ${test8}
)
