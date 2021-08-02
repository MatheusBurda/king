#include "Obstacle.h"
Obstacle::Obstacle(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit) :
	Entity(id, GM, pos, hit) {
	changePosition(pos);
}
Obstacle::~Obstacle() {

}