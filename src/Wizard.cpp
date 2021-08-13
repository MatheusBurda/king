#include "Wizard.h"

#include "Animation.h"

const float Wizard::attackTime = 1.2;

Wizard::Wizard(sf::Vector2f pos, Fireball* fireb, Player* pPlayer1, Player* pPlayer2) :
Enemy(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), WIZARD_LIFE, WIZARD_DAMAGE, pPlayer1, pPlayer2),
maxHeight(pos.y - MAX_VAR_HEIGHT),
minHeight(pos.y) {
    totalTimeFromAttack = 0;
    fireball = fireb;
    initializeSprite();
    setVelocity(sf::Vector2f(0, WIZARD_VELOCITY));
}

Wizard::~Wizard() {
}

void Wizard::initializeSprite() {
    sprite->initializeTexture(WIZARD_PATH, sf::Vector2u(4, 5));
}

void Wizard::update(float dt) {
    if ((position.y > minHeight) && velocity.y > 0)
        velocity.y *= -1;
    else if ((position.y < maxHeight) && velocity.y < 0)
        velocity.y *= -1;
    if (totalTimeFromAttack >= attackTime && getShowing()) {
        fireball->setShowing(false);
        setIsAttacking(true);
    }
    changePosition(Vector2f(position.x, velocity.y * dt + position.y));
    if (life <= 0) {
        setShowing(false);
        fireball->setShowing(false);
    }
    sprite->Update(2, dt, facingLeft(), position);
    totalTimeFromAttack += dt;
    attack();
}

/* Throws Fireball at players direction*/
void Wizard::attack() {
    if (getIsAttacking() && totalTimeFromAttack >= attackTime) {
        fireball->changePosition(getPosition() + sf::Vector2f(WIZARD_WIDTH, 0));
        if (facingLeft()) {
            fireball->setVelocity(sf::Vector2f(-FIREBALL_VELOCITYX, 0));
        } else {
            fireball->setVelocity(sf::Vector2f(FIREBALL_VELOCITYX, 0));
        }
        fireball->setShowing(true);
        setIsAttacking(false);
        totalTimeFromAttack = 0;
    }
}

/* Save Wizard and its fireball. */
void Wizard::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Wizard.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y - 30 << ' ' << getVelocity().x << ' ' << getVelocity().y << ' ' << fireball->getPosition().x << ' ' << fireball->getPosition().y - 30 << ' ' << fireball->getVelocity().x << ' ' << fireball->getVelocity().y << ' ' << fireball->getShowing() << ' ' << getLife() << ' ' << facingLeft() << endl;
        file.close();
    }
}
