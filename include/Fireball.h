#pragma once
#include "Entity.h"

class Animation;
class GraphicManager;

#define PATH_FIREBALL_TEXTURE "./assets/Projectiles/Fireball.png"

class Fireball : public Entity {
public:
    Fireball(ID::ids id, sf::Vector2f pos, sf::Vector2f hit);
    ~Fireball();
    void update(float dt);
    void render();
    void initializeSprite();
    void save(){ }
};
