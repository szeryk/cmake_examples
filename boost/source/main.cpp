#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

namespace fs = boost::filesystem;

void searchFilesWithRegex(const fs::path& directory_path, const std::string& pattern) {
    if (fs::exists(directory_path) && fs::is_directory(directory_path)) {
        boost::regex reg_expr(pattern);

        for (const auto& entry : fs::directory_iterator(directory_path)) {
            if (fs::is_regular_file(entry.path())) {
                std::string filename = entry.path().filename().string();

                if (boost::regex_search(filename, reg_expr)) {
                    std::cout << "File matching pattern '" << pattern << "': " << filename << std::endl;
                }
            }
        }
    } else {
        std::cout << "Directory does not exist or is not accessible!" << std::endl;
    }
}

int main() {
    fs::path directory_path(".");  // Replace with your directory path
    std::string search_pattern = ".*\\.txt";       // Replace with your desired regex pattern

    searchFilesWithRegex(directory_path, search_pattern);

    return 0;
}
