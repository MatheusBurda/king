#pragma once

#include "Entity.h"
#include "stdafx.h"

#define WALL_PATH_DIRT "./assets/Platforms/DirtWall.png"
#define WALL_PATH_BRICK "./assets/Platforms/BrickWall.png"
#define WALL_PATH_COBBLE "./assets/Platforms/CobbleWall.png"

#define WALL_HEIGHT 45
#define WALL_WIDTH 45

class Animation;
class GraphicManager;
class Wall : public Entity {
private:
    char path[100];

public:
    Wall(sf::Vector2f pos, const char* path);
    ~Wall();
    void update(float dt);
    void initializeSprite() { }
    void save();
};
