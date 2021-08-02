#pragma once
#include "Entity.h"
class Obstacle :
    public Entity
{

public:
    Obstacle(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit);
    ~Obstacle();
    virtual void update(float dt) {
    }
    virtual void render() {
    }
    void initializeSprite()=0;
};

