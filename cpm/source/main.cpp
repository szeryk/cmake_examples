#include <iostream>

#include "fmt/core.h"

int main() {
    std::string name = "Eryk";
    int number = 42;
    std::string formatted = fmt::format("hello {}. My favourite number is {}!", name, number);

    std::cout << formatted << std::endl;
}