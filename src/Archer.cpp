#include "Archer.h"

#include "Animation.h"
#include <math.h>

const float Archer::attackTime = 0.8;

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
    velocity = Vector2f(0, velocity.y + GRAVITY * dt);


    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(position.x, velocity.y * dt + position.y));

    updateSprite(dt);

    /* It will attack if its possible */
    attackCooldown += dt;
    if (attackCooldown >= attackTime * 4 && !arrow->getShowing() && getShowing()) {
        /* *************************************************** Adiciona aqui a condiçao do player estar perto ou nao dele para poder atacar */
        if(abs(getNearestPlayer()->getPosition().x-position.x)<= ARCHER_ATTACKX)
        isAttacking = true;
        if (getNearestPlayer()->getPosition().x - position.x > 0) {
            setFacingLeft(false);
        }
        else
            setFacingLeft(true);
        attackCooldown = 0;
    }
}

void Archer::attack() {
    Player* pPlayer = getNearestPlayer();
    sf::Vector2f posPlayer = pPlayer->getPosition();
    int deltaH = (posPlayer.y- position.y);
    float time = abs(posPlayer.x - position.x)/ARROW_VELOCITYX;
    int vy = -(deltaH+GRAVITY*time*time/2)/time;
    if (facingLeft()) {
        arrow->changePosition(getPosition() - sf::Vector2f(ARCHER_WIDTH, 0));
        arrow->setVelocity(sf::Vector2f(-ARROW_VELOCITYX, vy));
    } else {
        arrow->changePosition(getPosition()+sf::Vector2f(ARCHER_WIDTH, 0));
        arrow->setVelocity(sf::Vector2f(ARROW_VELOCITYX, vy));
    }
    arrow->setShowing(true);
    setIsAttacking(false);
    totalTimeFromAttack = 0;
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
        file << getPosition().x << ' '
             << getPosition().y - 30 << ' '
             << getVelocity().x << ' '
             << getVelocity().y << ' '
             << arrow->getPosition().x << ' '
             << arrow->getPosition().y - 30 << ' '
             << arrow->getVelocity().x << ' '
             << arrow->getVelocity().y << ' '
             << arrow->getShowing() << ' '
             << getLife() << ' '
             << facingLeft() << endl;
        file.close();
    }
}

void Archer::updateSprite(float dt) {
    if (isAttacking) {
        totalTimeFromAttack += dt;
        if (totalTimeFromAttack < attackTime) {
            sprite->Update(2, dt, facingLeft(), position);
        } else {
            attack();
        }
    } else
        sprite->Update(0, dt, facingLeft(), position);
}