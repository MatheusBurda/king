#pragma once

#include "Entity.h"

class Being : public Entity {

public:
    Being();
    ~Being();
    int attack();
    void getHurt(int enemydmg);
    bool amAlive();

protected:
    int life;
    int damage;
    virtual void update() {
    }
    virtual void render() {
    }
    virtual void colliding(Entity *ent){}
};
