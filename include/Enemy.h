#pragma once

#include "Character.h"
#include "Fireball.h"
class Animation;
class GraphicManager;

#define PATH_ENEMY_TEXTURE "./assets/EvilWizard/IdleBig.png"

class Enemy : public Character {
    Fireball *fireball;

public:
    Enemy(GraphicManager* GM);
    ~Enemy();
    void update(float dt);
    void render();
    void initializeSprite();
    void attack();
    void setFireball(Fireball* fb) { fireball = fb; }
};
