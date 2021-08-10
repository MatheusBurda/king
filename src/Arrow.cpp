#include "Arrow.h"

#include "Animation.h"

Arrow::Arrow(ID::ids id, sf::Vector2f pos, sf::Vector2f hit) :
Entity(id, pos, hit) {
    setShowing(false);
    initializeSprite();
}

Arrow::~Arrow() {
}

void Arrow::update(float dt) {
    if (velocity.x < 0)
        setFacingLeft(true);
    if (getShowing()) {
        velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
        changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
        sprite->Update(0, dt, facingLeft(), position);
        if (position.x > 120 * 60 || position.y > 120 * 14)
            setShowing(false);
    }
}

void Arrow::initializeSprite() {
    sprite->initializeTexture(PATH_ARROW_TEXTURE, sf::Vector2u(2, 1));
}