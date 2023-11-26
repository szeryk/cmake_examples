#include <iostream>
#include <string>
#include "calculator.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: ./cli_based_calculator <double> <double> <operation>" << std::endl;
        return 1;
    }

    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    std::string operation = argv[3];

    double result = calculate(a, b, operation);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
