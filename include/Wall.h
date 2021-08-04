#pragma once

#include "Entity.h"

#define WALL_PATH_DIRT "./assets/Platforms/DirtWall.png"
#define WALL_PATH_BRICK "./assets/Platforms/BrickWall.png"
#define WALL_PATH_COBBLE "./assets/Platforms/CobbleWall.png"
  
class Animation;
class GraphicManager;
class Wall : public Entity {
public:
    Wall(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, const char* path);
    ~Wall();
    void update(float dt);
    void render();
    void initializeSprite(){}
};
