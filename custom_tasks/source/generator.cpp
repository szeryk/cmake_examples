#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("on_the_fly.cpp");

    if (file.is_open()) {
        file << "#include <iostream>\n\nint main() {\n";
        file << "    std::cout << \"I've been generated on the fly!!!\" << std::endl;\n";
        file << "    return 0;\n}\n";
        file.close();
        std::cout << "on_the_fly.cpp has been generated!" << std::endl;
    } else {
        std::cerr << "Unable to create on_the_fly.cpp" << std::endl;
        return 1;
    }

    return 0;
}
