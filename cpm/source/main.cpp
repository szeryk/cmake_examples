#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <fmt/core.h>

using json = nlohmann::json;

int main() {
    // Read JSON file
    std::ifstream file("../source/data.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    // Parse JSON
    json jsonData;
    try {
        file >> jsonData;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << '\n';
        return 1;
    }

    // Access and print values
    std::string name = jsonData["name"];
    int age = jsonData["age"].get<int>(); // Retrieve age as integer
    bool isStudent = jsonData["is_student"];

    // Retrieve grades as integers
    std::vector<int> grades;
    for (const auto& grade : jsonData["grades"]) {
        grades.push_back(grade.get<int>());
    }

    std::string street = jsonData["address"]["street"];
    std::string city = jsonData["address"]["city"];
    std::string country = jsonData["address"]["country"];

    fmt::print("Name: {}\n", name);
    fmt::print("Age: {}\n", age);
    fmt::print("Is Student: {}\n", isStudent ? "Yes" : "No");

    fmt::print("Grades: ");
    for (const auto& grade : grades) {
        fmt::print("{} ", grade);
    }
    fmt::print("\n");

    fmt::print("Address: {}, {}, {}\n", street, city, country);

    return 0;
}
