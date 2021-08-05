#include "Background.h"

#include "Animation.h"

Background::Background(sf::Vector2f pos, const char* path) :
Ent(ID::background, pos) {
    sprite->initializeTexture(path, sf::Vector2u(1, 1));
}

Background::~Background() {
}

void Background::initializeSprite() {
}

void Background::render() {
    sprite->Update(0, 0, false, position);
    sprite->render();
}