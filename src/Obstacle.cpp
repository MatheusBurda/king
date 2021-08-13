#include "Obstacle.h"
Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f hit, int efct, ID::ids id) :
	Entity(id, pos, hit), effect(efct){


}