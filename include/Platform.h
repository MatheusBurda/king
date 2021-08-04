#pragma once

#include "Entity.h"


#define PLATFORM_PATH1 "./assets/Platforms/BrickBlock.png"
#define PLATFORM_PATH2 "./assets/Platforms/CobbleBlock.png"

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
