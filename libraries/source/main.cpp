#include <iostream>
#include "MathFunctions.h"
// #include "SciencePrinter.h"

int main() {
    const double test_value = 4;
    std::cout << "Calculating square root of: " << test_value << std::endl;
    double result = mathfunctions::sqrt(test_value);
    std::cout << "Result: " << result << std::endl;
    // science::print(result);
}