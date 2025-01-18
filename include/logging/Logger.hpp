#pragma once

#include <string>

class Logger {
   public:
    Logger();
    ~Logger();

    void Info(const std::string& infos...);
};
