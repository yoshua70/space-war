#pragma once

#include <string>
#include "logging/Logger.hpp"

class Game {
   private:
    std::string m_configFile;
    Logger m_logger;

    bool init();

   public:
    Game();
    ~Game();

    Game(const std::string &configFile);

    void run();
};
