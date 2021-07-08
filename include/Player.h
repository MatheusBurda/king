#pragma once

#include "Being.h"

class Player : public Being {
public:
    Player();
    void update();
    void render();
};
