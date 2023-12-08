#include <iostream>
#include <chrono>

unsigned long long sumNumbers(int n) {
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int n = 1000000000; // Adjust the value of 'n' to a suitable number

    auto start = std::chrono::high_resolution_clock::now();
    unsigned long long result = sumNumbers(n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Sum: " << result << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
