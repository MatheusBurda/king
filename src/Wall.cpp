#include "Animation.h"
#include "GraphicManager.h"
#include "Wall.h"
Wall::Wall(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit) : Obstacle(id, GM, pos, hit){
	initializeSprite();
}
Wall::~Wall() {

}
void Wall::update(float dt) {
	sprite->Update(0, dt, false, position);
}
void Wall:: render() {
	sprite->render();
}
void Wall:: initializeSprite() {
	sprite->initializeTexture(WALL_PATH, id, sf::Vector2u(1, 1));
}