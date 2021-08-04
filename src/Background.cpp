#include "Background.h"

#include "Animation.h"

Background::Background(GraphicManager* GM, sf::Vector2f pos, const char* path) :
Ente(ID::background, GM, pos) {
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