#ifndef LOGGIN_H
#define LOGGIN_H

#include <string>
#include <chrono>
#include <ctime>
#include <iostream>

void log(std::string str) {
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a time_t object
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t object to a local time string
    std::cout << std::ctime(&currentTime) << ":" << str << std::endl;
};

#endif // LOGGIN_H
