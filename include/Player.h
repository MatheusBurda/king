#pragma once

#include "Character.h"

class GraphicManager;

#define PLAYER_PATH "./assets/King/king.png"

class Player : public Character {

public:
    Player(GraphicManager* GM);
    ~Player();
    void update(float dt);
    void render();
    void colliding(Entity* ent);
};
