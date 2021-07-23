#include "Being.h"

Being::Being(): life(-1), damage(-1) {
}

Being::~Being() {
}

int Being::attack() {
    return damage;
}
void Being::getHurt(int enemydmg) {
    life -= enemydmg;
}
bool Being::amAlive() {
    if (life > 0)
        return true;
    return false;
}