#include "Boss.h"
#include "Animation.h"

const float Boss::attackTime = 1.6;

Boss ::Boss(sf::Vector2f pos, Player* pPlayer1, Player* pPlayer2) :
Enemy(ID::boss, pos, sf::Vector2f(BOSS_WIDTH, BOSS_HEIGHT), BOSS_LIFE, BOSS_DMG, pPlayer1, pPlayer2) {
    initializeSprite();
    firstAttack = false;
}

Boss::~Boss() {
}

void Boss::initializeSprite() {
    sprite->initializeTexture(BOSS_PATH, sf::Vector2u(8, 6));
}

void Boss::update(float dt) {
    if (life <= 0) {
        setShowing(false);
        return;
    }

    velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);

    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    motionBoss();
    updateSprite(dt);

    /* It will attack if its possible */
    attackCooldown += dt;
    if (attackCooldown >= attackTime * 3) {
        if (abs(getNearestPlayer()->getPosition().x - position.x) <= BOSS_ATTACKX)
            attack();
    }
}
void Boss::motionBoss() {
    float dx = getNearestPlayer()->getPosition().x - position.x;
    if (abs(dx) < BOSS_MOTIONX_MAX && abs(dx) > BOSS_MOTIONX_MIN) {
        if (dx > 0) {
            setVelocity(sf::Vector2f(BOSS_VELOCITYX, getVelocity().y));
            setFacingLeft(false);
        } else {
            setVelocity(sf::Vector2f(-BOSS_VELOCITYX, getVelocity().y));
            setFacingLeft(true);
        }
    } else {
        setVelocity(sf::Vector2f(0, getVelocity().y));
    }
}

void Boss::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Boss.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y - 50 << ' ' << getVelocity().x << ' ' << getVelocity().y << ' ' << getLife() << ' ' << facingLeft() << endl;
        file.close();
    }
}

void Boss::updateSprite(float dt) {
    /* Attacking */
    if (isAttacking && timeAttacking <= attackTime) {
        timeAttacking += dt;
        if (firstAttack)
            sprite->Update(4, dt, facingLeft(), position);
        else
            sprite->Update(5, dt, facingLeft(), position);
    }
    /* Walking */
    else if (abs(velocity.x) > 0.001)
        sprite->Update(1, dt, facingLeft(), position);
    /* Idle */
    else
        sprite->Update(0, dt, facingLeft(), position);
}

void Boss::attack() {
    int dx = getNearestPlayer()->getPosition().x - position.x;
    if (abs(dx) <= BOSS_ATTACKX) {
        if (facingLeft() && dx < 0)
            getNearestPlayer()->getHurt(BOSS_DMG);
        else if (!facingLeft() && dx > 0)
            getNearestPlayer()->getHurt(BOSS_DMG);
        setIsAttacking(true);
        firstAttack = !firstAttack;
        attackCooldown = 0;
        timeAttacking = 0;
    }
}