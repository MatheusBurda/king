#pragma once

#include "Entity.h"

#define PLATFORM_PATH "./assets/Platforms/BrickPlatformSmall.png"

class GraphicManager;

class Platform : public Entity {

public:
    Platform(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Platform();
    void update(float dt);
    void render();
    void initializeSprite();
};
