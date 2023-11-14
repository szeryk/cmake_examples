cmake_minimum_required(VERSION 3.2)
project(StringMathListExercise)

# list exercise
set(myList 4 5 0 9 1 2137 1024)
list(SORT myList COMPARE NATURAL) # without compare natural sorting is alphabetical
list(GET myList 0 firstElement)
message("Smallest element: ${firstElement}")
message("Sorted list: ${myList}")

# string
set(myPath "/home/eryk/dir/file.txt")
string(FIND ${myPath} "/" lastSlash REVERSE)
string(FIND ${myPath} "." dot REVERSE)
math(EXPR fileNameLen "${dot} - ${lastSlash} - 1")
message("file name length (without suffix) is ${fileNameLen}")

# other approach
string(REGEX MATCH "\\/[A-Za-z0-9_]+\\." matched ${myPath}) # match /word. for different words
string(LENGTH ${matched} matchedLen)
math(EXPR fileNameLenFromMatched "${matchedLen} - 2") # get rid of / and .
message("file name length (without suffix) from regex: ${fileNameLenFromMatched}")

# math exercise
math(EXPR resultInCm "5 * ((60 * 60) / 6)")
math(EXPR resultInM "${resultInCm} / 100")
message("Calculation result is: ${resultInM}m")



