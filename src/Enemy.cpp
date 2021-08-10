#include "Enemy.h"

#include "Animation.h"
#include "math.h"

Enemy::Enemy(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Character(id, pos, hit, lf, dmg) {
    totalTimeFromAttack = 0.0f;
}

Enemy::~Enemy() {
}
