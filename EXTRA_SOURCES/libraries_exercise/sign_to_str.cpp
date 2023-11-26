#include "sign_to_str.h"

std::string sign_to_str(std::string operation) {
    if (operation == "+") {
        return "add";
    } else if (operation == "-") {
        return "subtract";
    } else if (operation == "*") {
        return "multiply";
    } else if (operation == "/") {
        return "divide";
    } else {
        return "unknown";
    }
}