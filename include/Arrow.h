#pragma once

#include "Entity.h"

#define PATH_ARROW_TEXTURE "./assets/Projectiles/Arrow.png"

class Animation;
class GraphicManager;

class Arrow : public Entity {
public:
    Arrow(ID::ids id, sf::Vector2f pos, sf::Vector2f hit);
    ~Arrow();
    void update(float dt);
    void initializeSprite();
    void save() { }
};
