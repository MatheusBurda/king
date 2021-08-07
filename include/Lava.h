#pragma once
#include "Entity.h"
#define LAVA_PATH "./assets/Platforms/Lava.png"
class Lava :
    public Entity
{
public:
    Lava(ID::ids id, sf::Vector2f pos, sf::Vector2f hit);
    ~Lava();
    void update(float dt);
    void render();
    void initializeSprite() {}

};


