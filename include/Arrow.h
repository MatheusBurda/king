#pragma once

#include "Projectile.h"

#define PATH_ARROW_TEXTURE "./assets/Projectiles/Arrow.png"

#define ARROW_VELOCITYX 500
#define ARROW_HMAX 300
#define ARROW_HEIGHT 10
#define ARROW_WIDTH 48
#define ARROW_DAMAGE 50 

class Animation;
class GraphicManager;

class Arrow : public Projectile {
public:
    Arrow(sf::Vector2f pos);
    ~Arrow();
    void update(float dt);
    void initializeSprite();
    void save() { }
};
