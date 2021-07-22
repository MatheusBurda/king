#pragma once

#include "Being.h"

class Player : public Being {
    //
    int life;
    int damage;

public:
    Player();
    void update(float dt);
    void render();
    //
    int attack();
    void getHurt(int enemydmg);
    bool amAlive();
};
