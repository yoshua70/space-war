#include "logging/Logger.hpp"

#include <iostream>

Logger::Logger() = default;
Logger::~Logger() = default;

void Logger::Info(const std::string& infos...) {
    std::cout << "[INFO]";
    for (auto info : infos) {
        std::cout << " " << info;
    }
    std::cout << std::endl;
}
