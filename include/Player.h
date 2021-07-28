#pragma once

#include "Character.h"

class Animation;
class GraphicManager;

#define PLAYER_PATH "./assets/EvilWizard/EvilWizard.png"

class Player : public Character {
private:
    bool Canjump;

public:
    Player(GraphicManager* GM);
    ~Player();
    void update(float dt);
    void render();
    void setJump(const bool val = true) { Canjump = val; }
    void initializeSprite();
};
