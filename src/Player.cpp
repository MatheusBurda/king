#include "Player.h"

#include "Animation.h"
#include "GraphicManager.h"
#include <math.h>

const float Player::attackTime = 0.4;

Player::Player(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Character(ID::player, GM, pos, hit, lf, dmg) {
    isWalking = false;
    totalTime = 0.0f;
    firstAttack = true;
    Canjump = true;
    initializeSprite();
}

Player::~Player() {
}

void Player::update(float dt) {

    if (life <= 0) {
        setShowing(false);
    }
    if (isWalking)
        velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
    else
        velocity = Vector2f(velocity.x * 0.01f, velocity.y + GRAVITY * dt);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    /* Attacking */
    if (canAttack() != 0) {
        sprite->Update(canAttack(dt), dt, facingLeft(), position);
    }
    /* Idle */
    else if (abs(velocity.x) < 0.001)
        sprite->Update(0, dt, facingLeft(), position);
    /* Walking */
    else
        sprite->Update(1, dt, facingLeft(), position);
}

void Player::render() {
    sprite->render();
}

void Player::initializeSprite() {
    sprite->initializeTexture(PLAYER_PATH, id, sf::Vector2u(4, 6));
}

int Player::canAttack(float dt) {
    if (isAttacking) {
        totalTime += dt;
        if (totalTime < attackTime) {
            if (firstAttack)
                return 4;
            else
                return 5;
        } else {
            firstAttack = !firstAttack;
            totalTime = 0;
        }
        isAttacking = false;
    }
    return 0;
}

/* Walk left direction < TRUE
  Walk right direction = FALSE */
void Player::walk(bool left) {
    isWalking = true;
    if (left)
        velocity = Vector2f(-PLAYER_VELOCITY, velocity.y);
    else
        velocity = Vector2f(PLAYER_VELOCITY, velocity.y);

    setFacingLeft(left);
}

void Player::jump() {
    if (Canjump) {
        velocity = Vector2f(velocity.x, -sqrtf(2.0f * GRAVITY * PLAYER_JUMP));
        Canjump = false;
    }
}
