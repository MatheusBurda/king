#include "Character.h"

Character::Character(ID::ids id, GraphicManager* GM) :
Entity(id, GM),
life(-1), damage(-1) {
    isAttacking = false;
}

Character::~Character() {
}

void Character::attack(Character *ct) {
    ct->life -= damage;
}

void Character::getHurt(int enemydmg) {
    life -= enemydmg;
}

bool Character::amAlive() {
    if (life > 0)
        return true;
    return false;
}