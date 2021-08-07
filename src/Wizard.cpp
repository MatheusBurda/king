#include "Wizard.h"

#include "Animation.h"

const float Wizard::attackTime = 1.2;

Wizard::Wizard(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg, Fireball* fireb) :
Enemy(id, pos, hit, lf, dmg) {
    totalTimeFromAttack = 0;
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
    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    if (life <= 0) {
        setShowing(false);
        fireball->setShowing(false);
    }
    sprite->Update(2, dt, facingLeft(), position);
    totalTimeFromAttack += dt;
    attack();
}

void Wizard::attack() {
    if (getIsAttacking() && totalTimeFromAttack >= attackTime) {
        fireball->changePosition(getPosition() + sf::Vector2f(WIZARD_WIDTH, 0));
        if (facingLeft()) {
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, 0)); //, -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        } else {
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, 0)); // -sqrt(FIREBALL_HMAX * GRAVITY * 2)));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
        totalTimeFromAttack = 0;
    }
}
void Wizard::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Wizard.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y - 30 << ' ' << facingLeft() << endl;
        file.close();
    }
}