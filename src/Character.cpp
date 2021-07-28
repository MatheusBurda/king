#include "Character.h"

#include "Animation.h"
#include "GraphicManager.h"

Character::Character(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Entity(id, GM, pos, hit),
life(lf), damage(dmg) {
    isAttacking = false;
}

Character::~Character() {
}

int Character::attack() {
    return damage;
}

void Character::getHurt(int dmg) {
    life -= dmg;
}

bool Character::amAlive() {
    if (life > 0)
        return true;
    return false;
}