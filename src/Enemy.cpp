#include "Enemy.h"

#include "GraphicManager.h"
#include "Animation.h"

Enemy::Enemy(GraphicManager* GM) :
Character(ID::enemy, GM) {
    life = ENEMY_LIFE;
    damage = ENEMY_DAMAGE;

    setHitbox(sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT));

    changePosition(sf::Vector2f(400, 20));

    initializeSprite();
}

Enemy::~Enemy() {
}

void Enemy::update(float dt) {
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setIsAttacking(true);
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    if (life <= 0)
        setShowing(false);

    sprite->Update(0, dt, facingLeft(), position);
}

void Enemy::render() {
    sprite->render();
}

void Enemy::initializeSprite() {
    sprite->initializeTexture(PATH_ENEMY_TEXTURE, id, sf::Vector2u(8, 1));
}