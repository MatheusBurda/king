#include "Fireball.h"

#include "Animation.h"
#include "GraphicManager.h"

Fireball::Fireball(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit) :
Entity(id, GM, pos, hit) {
    setShowing(false);
    initializeSprite();
}

Fireball::~Fireball() {
}

void Fireball::update(float dt) {
    if (velocity.x < 0)
        setFacingLeft(true);
    if (getShowing()) {
        //velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
        changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
        sprite->Update(0, dt, facingLeft(), position);
        if (position.x > 120*60 || position.y > 120*14)
            setShowing(false);
    }
}

void Fireball::render() {
    sprite->render();
}

void Fireball::initializeSprite() {
    sprite->initializeTexture(PATH_FIREBALL_TEXTURE, id, sf::Vector2u(3, 1));
}