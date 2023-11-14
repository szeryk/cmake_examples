cmake_minimum_required(VERSION 3.2)
project(StringMathListDemo)

# list examples
message("List handling")
set(myList 4 5 test 9 1 one two ???)
list(GET myList 0 firstElement)
list(LENGTH myList myListLen)
list(FIND myList "one" findOneResult)
message("myList = ${myList}")
message("myList = " ${myList}) # why difference? because here list is unpacked and `message` command concats all inputs
message("firstElement = ${firstElement}")
message("myListLen = ${myListLen}")
message("is one in my list? ${findOneResult}")
message("")
message("")

message("Brackets problem")
set(regularList "a_a" "b_b")
set(withBrackets "a[a" "b]b")
list(LENGTH regularList lenNo)
list(LENGTH withBrackets lenWith)
list(GET regularList 0 firstNo)
list(GET withBrackets 0 firstWith)
message("Regular list: Length=${lenNo} --> First element=${firstNo}")
message("With brackets: Length=${lenWith} --> First element=${firstWith}")

# set(unbalancedBrackets "a[a" "b_b" "cc" "many")
# list(LENGTH unbalancedBrackets lenUn)
# list(GET unbalancedBrackets 0 firstUn)
# message("Unbalanced brackets: Length=${lenUn} --> First element=${firstUn}") # all gets glued...
message("")
message("")

# string
message("String handling")
set(exampleString "Hello, World!")
message("exampleString = ${exampleString}")
string(FIND exampleString "e" index_a)
string(FIND ${exampleString} "e" index_b)
message("e found at index_a = ${index_a}")
message("e found at index_b = ${index_b}")
string(TOLOWER ${exampleString} exampleToLower)
message("exampleToLower = ${exampleToLower}")
string(SUBSTRING ${exampleString} 3 5 exampleSubstring)
message("exampleSubstring = ${exampleSubstring}")
message("")
message("")

# math exercise
set(a 3)
set(b 7)
math(EXPR result "(${a}+${b}) * 2")
message("result as decimal = ${result}")
math(EXPR resultHex "(${a}+${b}) * 2" OUTPUT_FORMAT HEXADECIMAL) # CMake 3.13+ for hexadecimal
message("result as hexadecimal = ${resultHex}")
message("")
message("")
