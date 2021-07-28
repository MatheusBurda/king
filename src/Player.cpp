#include "Player.h"

#include "Animation.h"
#include "GraphicManager.h"
#include <math.h>

const float Player::attackTime = 0.8;

Player::Player(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Character(ID::player, GM, pos, hit, lf, dmg) {

    totalTime = 0.0f;
    firstAttack = true;
    Canjump = true;
    initializeSprite();
}

Player::~Player() {
}

void Player::update(float dt) {

    totalTime += dt;
    velocity = Vector2f(velocity.x * 0.05f, velocity.y + GRAVITY * dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity = Vector2f(PLAYER_VELOCITY, velocity.y);
        setFacingLeft(false);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity = Vector2f(-PLAYER_VELOCITY, velocity.y);
        setFacingLeft(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Canjump) {
        velocity = Vector2f(velocity.x, -sqrtf(2.0f * GRAVITY * PLAYER_JUMP));
        Canjump = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        setIsAttacking(true);
    else
        setIsAttacking(false);
    if (life <= 0) {
        setShowing(false);
    }

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    /* Attacking */
    if (canAttack() != 0) {
        sprite->Update(canAttack(), dt, facingLeft(), position);
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

int Player::canAttack() {
    if (totalTime > attackTime && isAttacking) {
        totalTime = 0;
        firstAttack = !firstAttack;
        if (firstAttack)
            return 4;
        else
            return 5;
    }
    return 0;
}