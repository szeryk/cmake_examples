#include <iostream>

#include "lib.h"

void expect_equal(int a, int b) {
    if (a != b) {
        std::cout << "Fail: Values don't match: " << a << "!=" << b << std::endl;
        exit(1);
    }
}

int main() {
    std::cout << "Unit testing add function started.\n";

    // custom unit test framework
    expect_equal(add(1, 1), 2);
    expect_equal(add(21, 37), 58);

    std::cout << "Tests passed.\n";
    return 0;
}
