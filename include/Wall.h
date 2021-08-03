#pragma once
#include "Obstacle.h"
#define WALL_PATH "./assets/Platforms/CobbleWall.png"
class Animation;
class GraphicManager;
class Wall :
    public Obstacle
{
public:
    Wall(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Wall();
    void update(float dt);
    void render();
    void initializeSprite();
};

