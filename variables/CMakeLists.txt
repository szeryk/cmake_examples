cmake_minimum_required(VERSION 3.26)
project(variables)

message("Hello world!")

# definition       value
set(var a b c)   # "a;b;c"
set(var a;b;c)   # "a;b;c"
set(var "a b c") # "a b c"
set(var a b;c)   # "a;b;c"
set(var a "b c") # "a;b c"
# message("List as string: ${var}")
# message("List as list: " ${var})

set(foo ab)               # foo = "ab"
set(bar ${foo}cd)         # bar = "abcd"
set(baz ${foo} cd)        # baz = "ab;cd"
set(myVar ba)             # myVar = "ba"
set(big "${${myVar}r}ef") # big = "${bar}ef" = "abcdef"
set(${foo} xyz)           # ab = "xyz"
set(bar ${notSetVar})     # bar = ""
# message("Not set var: " ${notSetVar})

# multi line var
set(myVar "myVar value")
set(multiLine "First line with ${myVar}
Second line has \"quoted\" string inside")
# message(${multiLine})

# LUA-like bracket syntax
# prevents substitions
set(shellScript [=[
#!/bin/bash
[[ -n "${USER}" ]] && echo "Have USER"
]=])
# message(${shellScript})

# unsetting
set(someVar test) # someVar = "test"
# message("someVar after set: " ${someVar})
unset(someVar)    # someVar = ""
# message("someVar after unset: " ${someVar})

# env vars can be obtained $ENV{varName}
set(copyOfPath $ENV{PATH})
# message("copyOfPath = " ${copyOfPath})
