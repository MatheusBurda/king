#pragma once
#include "Entity.h"

class Animation;

#define PATH_FIREBALL_TEXTURE "./assets/Projectiles/Fireball.png"

#define FIREBALL_WIDTH 40
#define FIREBALL_HEIGHT 24
#define FIREBALL_VELOCITYX 400
#define FIREBALL_HMAX 200

class Fireball : public Entity {
public:
    Fireball(sf::Vector2f pos);
    ~Fireball();
    void update(float dt);
    void initializeSprite();
    void save() { }
};
