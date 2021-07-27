#include "Platform.h"
#include "Animation.h"
#include "GraphicManager.h"

Platform::Platform(sf::Vector2f pos, GraphicManager* GM) :
Entity(ID::plataform, GM) {
    changePosition(pos);

    setHitbox(sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));

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