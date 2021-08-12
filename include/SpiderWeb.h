#pragma once

#include "Entity.h"
#define SPIDER_PATH "./assets/Platforms/SpiderWeb.png"

class SpiderWeb : public Entity {
public:
    SpiderWeb(sf::Vector2f pos);
    ~SpiderWeb();
    void update(float dt);

    void initializeSprite() { }
    void save();
};
