#include "divide.h"

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0; // Handle division by zero error
    }
}
