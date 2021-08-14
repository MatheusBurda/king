#include "Arrow.h"

#include "Animation.h"

Arrow::Arrow(sf::Vector2f pos) :
Entity(ID::arrow, pos, sf::Vector2f(ARROW_WIDTH, ARROW_HEIGHT)) {
    setShowing(false);
    initializeSprite();
}

Arrow::~Arrow() {
}

void Arrow::update(float dt) {
    if (velocity.x < 0)
        setFacingLeft(false);
    else
        setFacingLeft(true);
    if (getShowing()) {
        velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
        changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
        sprite->Update(0, dt, facingLeft(), position);
    }
}

void Arrow::initializeSprite() {
    sprite->initializeTexture(PATH_ARROW_TEXTURE, sf::Vector2u(2, 1));
}