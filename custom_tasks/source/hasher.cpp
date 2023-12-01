#include <iostream>
#include <fstream>
#include <cstdio> // for popen

using namespace std;

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        cerr << "popen failed!" << endl;
        return "";
    }
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    string filePath = argv[1];

    string command = "md5sum \"" + filePath + "\"";
    string md5hash = exec(command.c_str());

    if (!md5hash.empty()) {
        // Extracting only the hash part from the output
        size_t pos = md5hash.find(' ');
        if (pos != string::npos) {
            md5hash = md5hash.substr(0, pos);
            cout << "MD5 hash: " << md5hash << endl;

            // Save hash to hash.txt
            ofstream hashFile("hash_from_cpp.txt");
            if (hashFile.is_open()) {
                hashFile << md5hash;
                hashFile.close();
                cout << "MD5 hash has been saved in hash.txt" << endl;
            } else {
                cerr << "Unable to create hash.txt file" << endl;
                return 1;
            }
        } else {
            cerr << "Unable to extract MD5 hash" << endl;
            return 1;
        }
    } else {
        cerr << "Error calculating MD5 hash" << endl;
        return 1;
    }

    return 0;
}
