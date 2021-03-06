#pragma once

#include "Entity.h"

class Animation;
class GraphicManager;

class Character : public Entity {
protected:
    int life;
    int damage;
    bool isAttacking;

    virtual void update(float dt) = 0;
    virtual void initializeSprite() = 0;

public:
    Character(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg);
    ~Character();

    int attack();
    void getHurt(int dmg);

    void setIsAttacking(const bool val = false) { isAttacking = val; }
    bool getIsAttacking() const { return isAttacking; }

    virtual void save() = 0;
    void setLife(int lf) { life = lf; }
    int getLife() const;
    virtual void updateSprite(float dt) = 0;
};
