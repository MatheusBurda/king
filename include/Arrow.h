#pragma once
#include "Entity.h"
class Animation;
class GraphicManager;
#define PATH_ARROW_TEXTURE "./assets/Projectiles/Arrow.png"
class Arrow :
    public Entity
{
public:
    Arrow(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Arrow();
    void update(float dt);
    void render();
    void initializeSprite();
};

