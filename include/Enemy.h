#pragma once

#include "Character.h"
#include "Fireball.h"
class Animation;
class GraphicManager;

#define PATH_ENEMY_TEXTURE "./assets/EvilWizard/IdleBig.png"

class Enemy : public Character {
    Fireball *fireball;

public:
    Enemy(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball *fb);
    ~Enemy();
    void update(float dt);
    void render();
    void initializeSprite();
    void attack();
    void setFireball(Fireball* fb) { fireball = fb; }
};
