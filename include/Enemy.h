#pragma once

#include "Character.h"
#include "Fireball.h"

class Animation;
class Player;

class Enemy : public Character {
protected:
    float totalTimeFromAttack;
    Player* pPlayer1;
    Player* pPlayer2;
    float attackCooldown;

public:
    Enemy(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Player* pPlayer1 = NULL, Player* pPlayer2 = NULL);
    ~Enemy();
    virtual void update(float dt) = 0;
    virtual void attack() = 0;
    virtual void initializeSprite() = 0;
    virtual void save() = 0;
    Player* getNearestPlayer();
};
