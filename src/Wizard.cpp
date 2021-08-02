#include "Wizard.h"
#include "Animation.h"
#include "GraphicManager.h"
Wizard::Wizard(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball* fireb): Enemy(id, GM, pos, hit, lf, dmg) {
    fireball = fireb;
    initializeSprite();
}
Wizard::~Wizard() {

}
void Wizard::initializeSprite() {
    sprite->initializeTexture(WIZARD_PATH, id, sf::Vector2u(4, 5));
}
void Wizard::update(float dt) {

    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (!fireball->getShowing() && getShowing()) { //&& sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        setIsAttacking(true);
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    if (life <= 0)
        setShowing(false);

    sprite->Update(2, dt, facingLeft(), position);
    attack();
}

void Wizard::attack() {
    if (getIsAttacking()) {
        fireball->changePosition(getPosition() + sf::Vector2f(ENEMY_WIDTH, 0));
        if (facingLeft()) {
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, 0)); //, -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        else {
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, 0)); // -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
    }
}