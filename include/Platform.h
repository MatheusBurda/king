#pragma once

#include "Entity.h"

#define PLATFORM_PATH_DIRT "./assets/Platforms/DirtBlock.png"
#define PLATFORM_PATH_BRICK "./assets/Platforms/BrickBlock.png"
#define PLATFORM_PATH_COBBLE "./assets/Platforms/CobbleBlock.png"

#define PLATFORM_WIDTH 225
#define PLATFORM_HEIGHT 45

class GraphicManager;

class Platform : public Entity {
private:
    int platType;

public:
    Platform(sf::Vector2f pos, int platType = 1);
    ~Platform();
    void update(float dt);
    void initializeSprite();
    void save();
};
