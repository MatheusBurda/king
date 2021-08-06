#pragma once

#include "Character.h"
#include "Fireball.h"

class Animation;
class GraphicManager;

class Enemy : public Character {
protected:
    float totalTimeFromAttack;

public:
    Enemy(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Enemy();
    virtual void update(float dt) = 0;
    void render();
    virtual void attack() = 0;
    virtual void initializeSprite() = 0;
    virtual void save() = 0;
};
