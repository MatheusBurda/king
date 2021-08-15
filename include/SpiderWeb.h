#pragma once

#include "Obstacle.h"
#define SPIDER_PATH "./assets/Platforms/SpiderWeb.png"

class SpiderWeb : public Obstacle {
public:
    SpiderWeb(sf::Vector2f pos);
    ~SpiderWeb();
    void update(float dt);

    void initializeSprite() { }
    void save();
};
