#pragma once

#include "Entity.h"

#define LAVA_PATH "./assets/Platforms/Lava.png"

#define LAVA_DAMAGE 5
#define LAVA_WIDTH 225
#define LAVA_HEIGHT 45

class Lava : public Entity {
public:
    Lava(sf::Vector2f pos);
    ~Lava();
    void update(float dt);
    void initializeSprite() { }
    void save();
};
