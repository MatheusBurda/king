#pragma once

#include "Character.h"
#include "Fireball.h"

class Animation;
class GraphicManager;


class Enemy : public Character {

public:
    Enemy(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Enemy();
    virtual void update(float dt)=0;
    void render();
    virtual void attack()=0;
    virtual void initializeSprite()=0;
};
