#!/usr/bin/env python3

def generate_cpp_hello_world():
    cpp_code = '''#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
'''

    with open("../hello_world.cpp", "w") as file:
        file.write(cpp_code)

    print("C++ Hello World app generated by generator.py")

if __name__ == "__main__":
    generate_cpp_hello_world()