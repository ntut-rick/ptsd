#include "TwoCreditsValley/GameManager.hpp"

#include "Util/Logger.hpp"

using namespace TwoCreditsValley;

GameManager::GameManager(IO* io) {
    _io = io;
    _Giraffe = {
        .filePath = "../assets/sprites/giraffe.png",
        .topLeft = {0, 0},
        .scale = 1,
        .visible = true,
    };
}

void GameManager::Update() {
    _io->Draw(&_Giraffe);
}
