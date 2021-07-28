#include "Platform.h"
#include "Animation.h"
#include "GraphicManager.h"

Platform::Platform(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit) :
Entity(ID::platform, GM, pos, hit) {
    changePosition(pos);
    initializeSprite();
}

Platform::~Platform() {
}

void Platform::update(float dt) {
    sprite->Update(0, dt, false, position);
}

void Platform::render() {
    sprite->render();
}

void Platform::initializeSprite() {
    sprite->initializeTexture(PLATFORM_PATH, id, sf::Vector2u(1, 1));
}