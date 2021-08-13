#include "Projectile.h"
Projectile::Projectile(sf::Vector2f pos, sf::Vector2f hit, int damage, int timeActive, ID::ids id) :
Entity(id, pos, hit), Damage(damage), timeActive(timeActive){


}