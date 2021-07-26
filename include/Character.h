#pragma once

#include "Entity.h"

class Character : public Entity {
protected:
    int life;
    int damage;
    virtual void update(float dt) {
    }
    virtual void render() {
    }
    virtual void colliding(Entity* ent) { }

public:
    Character(ID::ids id, GraphicManager* GM);
    ~Character();
    int attack();
    void getHurt(int enemydmg);
    bool amAlive();

};
