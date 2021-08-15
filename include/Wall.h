#pragma once

#include "Obstacle.h"
#include "stdafx.h"

#define WALL_PATH_DIRT "./assets/Platforms/DirtWall.png"
#define WALL_PATH_BRICK "./assets/Platforms/BrickWall.png"
#define WALL_PATH_COBBLE "./assets/Platforms/CobbleWall.png"

#define WALL_HEIGHT 45
#define WALL_WIDTH 45

class Animation;
class GraphicManager;
class Wall : public Obstacle {
private:
    int wallType;

public:
    Wall(sf::Vector2f pos, int wallType = 1, bool facingLeft = false);
    ~Wall();
    void update(float dt);
    void initializeSprite();
    void save();
};
