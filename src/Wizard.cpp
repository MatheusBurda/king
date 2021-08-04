#include "Wizard.h"
#include "Animation.h"
#include "GraphicManager.h"
const float Wizard::attackTime = 1.2;
Wizard::Wizard(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball* fireb): Enemy(id, GM, pos, hit, lf, dmg) {
    totalTimeFromAttack =0;
    fireball = fireb;
    initializeSprite();
}
Wizard::~Wizard() {

}
void Wizard::initializeSprite() {
    sprite->initializeTexture(WIZARD_PATH, sf::Vector2u(4, 5));
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
    totalTimeFromAttack += dt;
    attack();
}

void Wizard::attack() {
    if (getIsAttacking() && totalTimeFromAttack >= attackTime) {
        fireball->changePosition(getPosition() + sf::Vector2f(WIZARD_WIDTH, 0));
        if (facingLeft()) {
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, 0)); //, -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        else {
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, 0)); // -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
        totalTimeFromAttack =0;
    }
}