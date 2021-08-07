#pragma once
#include "Entity.h"
#define SPIDER_PATH "./assets/Platforms/SpiderWeb.png"
class SpiderWeb :
    public Entity
{
public:
    SpiderWeb(ID::ids id, sf::Vector2f pos, sf::Vector2f hit);
    ~SpiderWeb();
    void update(float dt);
    void render();
    void initializeSprite() {}

};


