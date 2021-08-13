#pragma once
<<<<<<< Updated upstream
#include "Entity.h"
class Animation;
class GraphicManager;
#define PATH_ARROW_TEXTURE "./assets/Projectiles/Arrow.png"
class Arrow :
    public Entity
{
=======

#include "Projectile.h"

#define PATH_ARROW_TEXTURE "./assets/Projectiles/Arrow.png"

#define ARROW_VELOCITYX 500
#define ARROW_HMAX 100
#define ARROW_HEIGHT 10
#define ARROW_WIDTH 48
#define ARROW_DAMAGE 50
class Animation;
class GraphicManager;

class Arrow : public Projectile {
>>>>>>> Stashed changes
public:
    Arrow(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Arrow();
    void update(float dt);
    void render();
    void initializeSprite();
};

