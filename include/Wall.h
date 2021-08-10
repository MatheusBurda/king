#pragma once

#include "Entity.h"
#include "stdafx.h"

#define WALL_PATH_DIRT "./assets/Platforms/DirtWall.png"
#define WALL_PATH_BRICK "./assets/Platforms/BrickWall.png"
#define WALL_PATH_COBBLE "./assets/Platforms/CobbleWall.png"
  
class Animation;
class GraphicManager;
class Wall : public Entity {
private:
    char path[100];
public:
    Wall(ID::ids id,sf::Vector2f pos, sf::Vector2f hit, const char* path);
    ~Wall();
    void update(float dt);
    void render();
    void initializeSprite(){}
    void save();
};
