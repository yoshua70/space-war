#include "game_lib/Game.hpp"

Game::Game() = default;
Game::~Game() = default;

Game::Game(const std::string &configFile) : m_configFile{configFile} {
    m_logger.Info("configuration file path: ", m_configFile.c_str());
}

void Game::run() {
    init();
    m_logger.Info("Running..");
}

bool Game::init() { return true; }
