#include "Enemy.h"

#include "Animation.h"
#include "GraphicManager.h"
#include "math.h"

Enemy::Enemy(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball* fb) :
Character(ID::enemy, GM, pos, hit, lf, dmg) {
    fireball = fb;
    initializeSprite();
}

Enemy::~Enemy() {
}

void Enemy::update(float dt) {
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (!fireball->getShowing() && getShowing()){//&& sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setIsAttacking(true);
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    if (life <= 0)
        setShowing(false);

    sprite->Update(0, dt, facingLeft(), position);
    attack();
}

void Enemy::render() {
    sprite->render();
}

void Enemy::initializeSprite() {
    sprite->initializeTexture(PATH_ENEMY_TEXTURE, id, sf::Vector2u(8, 1));
}
void Enemy::attack() {
    if (getIsAttacking()) {
        fireball->changePosition(getPosition());
        if (facingLeft()) {
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, 0));//, -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        } else {
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, 0));// -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
    }
}