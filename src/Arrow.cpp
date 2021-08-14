#include "Arrow.h"

#include "Animation.h"

Arrow::Arrow(sf::Vector2f pos) :
Projectile(ID::arrow, pos, sf::Vector2f(ARROW_WIDTH, ARROW_HEIGHT), ARROW_DAMAGE) {
    setShowing(false);
    initializeSprite();
}

Arrow::~Arrow() {
}

void Arrow::update(float dt) {
    if (getShowing()) {
        updateActive(dt);
        velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
        changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
        sprite->Update(0, dt, facingLeft(), position);
    }
}

void Arrow::initializeSprite() {
    sprite->initializeTexture(PATH_ARROW_TEXTURE, sf::Vector2u(2, 1));
}