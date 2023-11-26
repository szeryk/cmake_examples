#include "calculator.h"
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"

double calculate(double a, double b, const std::string& operation) {
    if (operation == "add") {
        return add(a, b);
    } else if (operation == "subtract") {
        return subtract(a, b);
    } else if (operation == "multiply") {
        return multiply(a, b);
    } else if (operation == "divide") {
        return divide(a, b);
    }

    return 0; // Default return in case of unsupported operation
}
