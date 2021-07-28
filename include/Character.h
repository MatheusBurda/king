#pragma once

#include "Entity.h"

class Animation;
class GraphicManager;

class Character : public Entity {
protected:
    int life;
    int damage;
    bool isAttacking;

    virtual void update(float dt) {
    }
    virtual void render() {
    }
    virtual void colliding(Entity* ent) { }

public:
    Character(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Character();
    int attack();
    void getHurt(int dmg);
    bool amAlive();
    void setIsAttacking(const bool val = false) { isAttacking = val; }
    bool getIsAttacking() { return isAttacking; }
    virtual void initializeSprite() = 0;
};
