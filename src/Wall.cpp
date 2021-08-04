#include "Wall.h"
#include "Animation.h"
#include "GraphicManager.h"
Wall::Wall(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, const char* path) :
Obstacle(id, GM, pos, hit) {
    sprite->initializeTexture(path, sf::Vector2u(1, 1));
}

Wall::~Wall() {
}

void Wall::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void Wall::render() {
    sprite->render();
}
