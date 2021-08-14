#include "Enemy.h"

#include "Animation.h"
#include "Player.h"
#include "math.h"

Enemy::Enemy(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Player* pPlayer1, Player* pPlayer2) :
Character(id, pos, hit, lf, dmg),
pPlayer1(pPlayer1),
pPlayer2(pPlayer2),
attackCooldown(0.0) {
    totalTimeFromAttack = 0.0f;
}

Enemy::~Enemy() {
}

Player* Enemy::getNearestPlayer() {
    int x1, x2;
    if (pPlayer2) {
        x1 = abs(pPlayer1->getPosition().x - position.x);
        x2 = abs(pPlayer2->getPosition().x - position.x);
        if (x1 < x2)
            return pPlayer1;
        else
            return pPlayer2;
    }
    else
        return pPlayer1;
}
