#include "Archer.h"

#include "Animation.h"
#include "GraphicManager.h"
#include <math.h>

Archer::Archer(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Arrow* arr) :
Enemy(id, GM, pos, hit, lf, dmg) {
    arrow = arr;
    initializeSprite();
}

Archer::~Archer() {
}

void Archer::initializeSprite() {
    sprite->initializeTexture(ARCHER_PATH, sf::Vector2u(6, 5));
}

void Archer::update(float dt) {

    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (!arrow->getShowing() && getShowing()) {
        setIsAttacking(true);
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    if (life <= 0)
        setShowing(false);

    sprite->Update(2, dt, facingLeft(), position);
    attack();
}

void Archer::attack() {
    if (getIsAttacking()) {
        arrow->changePosition(getPosition() + sf::Vector2f(ENEMY_WIDTH, 0));
        if (facingLeft()) {
            arrow->setVelocity(sf::Vector2f(-ARROW_VELOCITYX, -sqrt(ARROW_HMAX * GRAVITY * 2)));
        } else {
            arrow->setVelocity(sf::Vector2f(ARROW_VELOCITYX, -sqrt(ARROW_HMAX * GRAVITY * 2)));
        }
        arrow->setShowing(true);
        setIsAttacking(false);
    }
}