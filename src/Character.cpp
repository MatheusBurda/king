#include "Character.h"

#include "Animation.h"

Character::Character(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Entity(id, pos, hit),
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
