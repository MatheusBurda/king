#pragma once

#include "Entity.h"

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
    Character(ID::ids id, GraphicManager* GM);
    ~Character();
    int attack();
    void getHurt(int dmg);
    bool amAlive();
    void setIsAttacking(const bool val = false) { isAttacking = val; }
    bool getIsAttacking() { return isAttacking; }
    bool facingLeft() { return (velocity.x < 0); }
};
