#include <iostream>
#include <string>
#include "calculator.h"
#include "sign_to_str.h"

int main() {
    double a, b;
    std::string operation;

    while (true) {
        std::cout << "Enter operation, one of + - / * (or type 'exit' to quit): ";
        std::cin >> operation;

        if (operation == "exit") {
            break;
        }

        operation = sign_to_str(operation);
        if (operation == "unknown")
        {
            std::cout << "Unkown operation. Must be one of: + - / *";
            continue;
        }


        std::cout << "Enter first number: ";
        std::cin >> a;
        std::cout << "Enter second number: ";
        std::cin >> b;

        double result = calculate(a, b, operation);
        std::cout << "The result of " << a << " " << operation << " " << b << " is " << result << std::endl;
    }

    return 0;
}
