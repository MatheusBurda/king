#include "Projectile.h"

const float Projectile::maxTimeActive = 5.0;

Projectile::Projectile(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int damage) :
Entity(id, pos, hit),
Damage(damage),
timeActive(0.0) { }

Projectile::~Projectile() { }

void Projectile::shoot(sf::Vector2f pos, sf::Vector2f velo) {
    setVelocity(velo);
    changePosition(pos);
    timeActive = 0.0;
    setShowing(true);
    if (velo.x < 0)
        setFacingLeft(true);
    else
        setFacingLeft(false);
}

void Projectile::updateActive(float dt) {
    timeActive += dt;
    if (timeActive > maxTimeActive)
        setShowing(false);
}

int Projectile::getDamage() const {
    return Damage;
}