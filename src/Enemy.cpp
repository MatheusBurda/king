#include "Enemy.h"
#include "Animation.h"
#include "GraphicManager.h"
#include "math.h"


Enemy::Enemy(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg):
Character(id, GM, pos, hit, lf, dmg) {
    totalTimeFromAttack = 0.0f;
}

Enemy::~Enemy() {
}

void Enemy::render() {
    sprite->render();
}


