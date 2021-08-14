#pragma once

#include "Entity.h"

class Obstacle : public Entity {
protected:
    float effect;

public:
    Obstacle(sf::Vector2f pos, sf::Vector2f hit, int efct, ID::ids id);
    virtual ~Obstacle() { }
    float getEffect() const { return effect; }
};