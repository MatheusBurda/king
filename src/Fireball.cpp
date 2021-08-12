#include "Fireball.h"

#include "Animation.h"
#include "GraphicManager.h"

Fireball::Fireball(sf::Vector2f pos) :
Entity(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT)) {
    setShowing(false);
    initializeSprite();
}

Fireball::~Fireball() {
}

void Fireball::update(float dt) {
    if (velocity.x < 0)
        setFacingLeft(true);
    if (getShowing()) {
        changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
        sprite->Update(0, dt, facingLeft(), position);
    }
}

void Fireball::initializeSprite() {
    sprite->initializeTexture(PATH_FIREBALL_TEXTURE, sf::Vector2u(3, 1));
}