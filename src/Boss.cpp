#include "Boss.h"
#include "Animation.h"

const float Boss::attackTime = 1.2;

Boss ::Boss(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Enemy(id, pos, hit, lf, dmg) {
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
    
    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);

    if (totalTimeFromAttack >= attackTime) {
        setIsAttacking(true);
        totalTimeFromAttack = 0;
    }

    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));

    totalTimeFromAttack += dt;

    sprite->Update(1, dt, facingLeft(), position);
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
        file << getPosition().x << ' ' << getPosition().y - 30 << endl;
        file.close();
    }
}
