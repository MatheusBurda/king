#include "Enemy.h"

#include "GraphicManager.h"
#include "Animation.h"

Enemy::Enemy(GraphicManager* GM) :
Character(ID::enemy, GM){
    life = ENEMY_LIFE;
    damage = ENEMY_DAMAGE;
    fireball = NULL;
    setHitbox(sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT));

    changePosition(sf::Vector2f(400, 20));

    initializeSprite();
}

Enemy::~Enemy() {
}

void Enemy::update(float dt) {
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !fireball->getShowing() && getShowing()) {
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
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, -sqrt(FIREBALL_HMAX*GRAVITY*2)));
        }else{
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
    }
}