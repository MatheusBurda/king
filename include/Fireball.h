#pragma once
#include "Projectile.h"

class Animation;
class GraphicManager;

#define PATH_FIREBALL_TEXTURE "./assets/Projectiles/Fireball.png"

<<<<<<< Updated upstream
class Fireball : public Entity {
=======
#define FIREBALL_WIDTH 40
#define FIREBALL_HEIGHT 24
#define FIREBALL_VELOCITYX 400
#define FIREBALL_HMAX 200
#define FIREBALL_DAMAGE 50

class Fireball : public Projectile {
>>>>>>> Stashed changes
public:
    Fireball(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Fireball();
    void update(float dt);
    void render();
    void initializeSprite();
};
