#include "Wizard.h"

#include "Animation.h"

const float Wizard::attackTime = 0.3;

Wizard::Wizard(sf::Vector2f pos, Fireball* fireb, Player* pPlayer1, Player* pPlayer2, int minH, int maxH) :
Enemy(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), WIZARD_LIFE, WIZARD_DAMAGE, pPlayer1, pPlayer2),
fireball(fireb) {

    initializeSprite();
    setVelocity(sf::Vector2f(0, WIZARD_VELOCITY));

    if (minH == 0)
        minHeight = int(pos.y);
    else
        minHeight = minH;

    if (maxH == 0)
        maxHeight = int(pos.y - MAX_VAR_HEIGHT);
    else
        maxHeight = maxH;
}

Wizard::~Wizard() {
}

void Wizard::initializeSprite() {
    sprite->initializeTexture(WIZARD_PATH, sf::Vector2u(4, 5));
}

void Wizard::update(float dt) {
    /* Check if died */
    if (life <= 0) {
        setShowing(false);
        fireball->setShowing(false);
    }
    /* Movement on y axis */
    if ((position.y > minHeight) && velocity.y > 0)
        velocity.y *= -1;
    else if ((position.y < maxHeight) && velocity.y < 0)
        velocity.y *= -1;
    changePosition(Vector2f(position.x, velocity.y * dt + position.y));
    updateSprite(dt);

    /* It will attack if its possible */
    attackCooldown += dt;
    if (attackCooldown >= attackTime * 10 && !fireball->getShowing() && getShowing()){
        /* *************************************************** Adiciona aqui a condiçao do player estar perto ou nao dele para poder atacar */
        if (abs(getNearestPlayer()->getPosition().x - position.x) <= WIZARD_ATTACKX) {
            isAttacking = true;
            if (getNearestPlayer()->getPosition().x - position.x > 0) {
                setFacingLeft(false);
            }
            else
                setFacingLeft(true);
            attackCooldown = 0;
        }
    }

}

/* Throws Fireball at players direction*/
void Wizard::attack() {
    Player* pPlayer = getNearestPlayer();
    int deltax, deltay;
    deltax = abs(pPlayer->getPosition().x - position.x);
    deltay = abs(pPlayer->getPosition().y - position.y);
    float teta = atanf(deltax / deltay);
    
    float vx, vy;
    vx = WIZARD_FIREBALL_VELOCITY * sin(teta);
    vy = WIZARD_FIREBALL_VELOCITY * cos(teta);
    if (facingLeft()) {
        fireball->changePosition(getPosition() - sf::Vector2f(WIZARD_WIDTH, 0));
        fireball->setVelocity(sf::Vector2f(-vx, vy));
    } else {
        fireball->changePosition(getPosition() + sf::Vector2f(WIZARD_WIDTH, 0));
        fireball->setVelocity(sf::Vector2f(vx, vy));
    }
    fireball->setShowing(true);
    setIsAttacking(false);
    totalTimeFromAttack = 0;
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
        file << getPosition().x << ' '
             << getPosition().y - 30 << ' '
             << getVelocity().x << ' '
             << getVelocity().y << ' '
             << fireball->getPosition().x << ' '
             << fireball->getPosition().y - 30 << ' '
             << fireball->getVelocity().x << ' '
             << fireball->getVelocity().y << ' '
             << fireball->getShowing() << ' '
             << getLife() << ' '
             << facingLeft() << ' '
             << minHeight << ' '
             << maxHeight << endl;
        file.close();
    }
}

void Wizard::updateSprite(float dt) {
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