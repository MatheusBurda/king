#include "Character.h"

Character::Character(ID::ids id, GraphicManager* GM) :
Entity(id, GM),
life(-1), damage(-1) {
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