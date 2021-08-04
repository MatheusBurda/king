#pragma once

#include "Entity.h"

#define PLATFORM_PATH_DIRT "./assets/Platforms/DirtBlock.png"
#define PLATFORM_PATH_BRICK "./assets/Platforms/BrickBlock.png"
#define PLATFORM_PATH_COBBLE "./assets/Platforms/CobbleBlock.png"

class GraphicManager;

class Platform : public Entity {

private:
    char path[100];
public:
     Platform(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, const char pt[100]);
    ~Platform();
    void update(float dt);
    void render();
    void initializeSprite();
};
