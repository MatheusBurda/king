#include "Platform.h"

Platform::Platform(sf::Vector2f pos) :
Entity(ID::plataform){
    position = pos;
    sprite.setSize(Vector2f(PLATFORM_WIDTH, PLAYER_HEIGHT));
    if (!texture.loadFromFile("./assets/Platforms/DirtPlatform.png")) {
        exit(9);
    }
    sprite.setTexture(&texture);
    sprite.setPosition(position);
}

Platform::~Platform() {
}

void Platform::update() {
    sprite.setPosition(position);
}

void Platform::render() {
    window->draw(sprite);
}
