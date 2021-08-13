#include "Archer.h"

#include "Animation.h"
#include <math.h>

const float Archer::attackTime = 1.2;

Archer::Archer(sf::Vector2f pos, Arrow* arr, Player* pPlayer1, Player* pPlayer2) :
Enemy(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ARCHER_LIFE, ARCHER_DAMAGE, pPlayer1, pPlayer2) {
    arrow = arr;
    initializeSprite();
}

Archer::~Archer() {
}

void Archer::initializeSprite() {
    sprite->initializeTexture(ARCHER_PATH, sf::Vector2u(6, 5));
}

void Archer::update(float dt) {
    if (life <= 0) {
        setShowing(false);
        arrow->setShowing(false);
    }
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);
    if (!arrow->getShowing() && getShowing()) {
        setIsAttacking(true);
    }

    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    totalTimeFromAttack += dt;
    sprite->Update(2, dt, facingLeft(), position);
    attack();
}

void Archer::attack() {
    if (getIsAttacking() && totalTimeFromAttack >= attackTime) {
        arrow->changePosition(getPosition() + sf::Vector2f(ARCHER_WIDTH, 0));
        if (facingLeft()) {
            arrow->setVelocity(sf::Vector2f(-ARROW_VELOCITYX, -sqrt(ARROW_HMAX * GRAVITY * 2)));
        } else {
            arrow->setVelocity(sf::Vector2f(ARROW_VELOCITYX, -sqrt(ARROW_HMAX * GRAVITY * 2)));
        }
        totalTimeFromAttack = 0;
        arrow->setShowing(true);
        setIsAttacking(false);
    }
}

//function used to save the Archer attributes in a txt
void Archer::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Archer.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y - 30 << ' ' <<getVelocity().x<<' '<<getVelocity().y <<' ' << arrow->getPosition().x << ' ' << arrow->getPosition().y - 30 << ' ' << arrow->getVelocity().x << ' ' << arrow->getVelocity().y << ' ' << arrow->getShowing() <<' ' << getLife() <<' ' << facingLeft() << endl;
        file.close();
    }
}
