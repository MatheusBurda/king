#pragma once

#include "Character.h"

class Animation;
class GraphicManager;

#define PLAYER_PATH "./assets/King/KingSpritesheet.png"

class Player : public Character {
private:
    bool Canjump;
    bool firstAttack;
    float totalTime;
    static const float attackTime;

public:
    Player(GraphicManager* GM);
    ~Player();
    void update(float dt);
    void render();
    void setJump(const bool val = true) { Canjump = val; }
    void initializeSprite();
    int canAttack();
};

