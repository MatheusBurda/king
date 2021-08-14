#pragma once

#include "Entity.h"

class Projectile : public Entity {
protected:
    int Damage;
    float timeActive;
    static const float maxTimeActive;

public:
    Projectile(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int damage);
    virtual ~Projectile();
    void shoot(sf::Vector2f pos, sf::Vector2f velo);
    void updateActive(float dt);
    int getDamage() const;
};