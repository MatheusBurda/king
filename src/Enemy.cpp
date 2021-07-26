#include "Enemy.h"

#include "GraphicManager.h"
Enemy::Enemy(GraphicManager* GM) :Character(ID::enemy, GM){
    life = ENEMY_LIFE;
    damage = ENEMY_DAMAGE;
    setHitbox(sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT));
    body.setOrigin(hitbox / 2.0f);
    body.setSize(hitbox);
    changePosition(sf::Vector2f(200, 20));
    body.setFillColor(sf::Color::Blue);
}
Enemy::~Enemy() {

}
void Enemy::update(float dt) {
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setIsAttacking(true);
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    body.setPosition(position);
    if (life <= 0)
        setShowing(false);
}

void Enemy::render() {
    pGraphicManager->getWindow()->draw(body);
}
