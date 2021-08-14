#pragma once
#include "Projectile.h"

class Animation;

#define PATH_FIREBALL_TEXTURE "./assets/Projectiles/Fireball.png"

#define FIREBALL_WIDTH 40
#define FIREBALL_HEIGHT 24
#define FIREBALL_VELOCITYX 400
#define FIREBALL_HMAX 200
#define FIREBALL_DAMAGE 100

class Fireball : public Projectile {
public:
    Fireball(sf::Vector2f pos);
    ~Fireball();
    void update(float dt);
    void initializeSprite();
    void save() { }
};
