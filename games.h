#pragma once

#include "dice.h"

enum GameStatus {
    PLAYING,
    WON,
    LOST
};

enum GameStatus playCraps();
