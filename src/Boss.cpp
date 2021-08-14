#include "Boss.h"
#include "Animation.h"

const float Boss::attackTime = 1.2;

Boss ::Boss(sf::Vector2f pos, Player* pPlayer1, Player* pPlayer2) :
Enemy(ID::boss, pos, sf::Vector2f(BOSS_WIDTH, BOSS_HEIGHT), BOSS_LIFE, BOSS_DMG, pPlayer1, pPlayer2) {
    initializeSprite();
}

Boss::~Boss() {
}

void Boss::initializeSprite() {
    sprite->initializeTexture(BOSS_PATH, sf::Vector2u(8, 6));
}

void Boss::update(float dt) {
    if (life <= 0) {
        setShowing(false);
    }

    velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);

    if (totalTimeFromAttack >= attackTime) {
        setIsAttacking(true);
        totalTimeFromAttack = 0;
    }

    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));

    updateSprite(dt);

    /* It will attack if its possible */
    attackCooldown += dt;
    if (attackCooldown >= attackTime * 10) {
        /* *************************************************** Adiciona aqui a condiçao do player estar perto ou nao dele para poder atacar */
        isAttacking = true;
    }
}

void Boss::save() {
    if (getShowing()) {
        cout << "TO SALVANDO UM BOSS" << endl;

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
/*     if (canAttack() != 0)
        sprite->Update(canAttack(dt), dt, facingLeft(), position); */
    /* Walking */
    if (abs(velocity.x) > 0.001)
        sprite->Update(1, dt, facingLeft(), position);
    /* Idle */
    else
        sprite->Update(0, dt, facingLeft(), position);
}
