#include "Player.h"

#include "Animation.h"
#include "GraphicManager.h"
#include <math.h>

const float Player::attackTime = 0.8;

Player::Player(ID::ids id, GraphicManager* GM, sf::Vector2f pos, sf::Vector2f hit, int lf, int dmg) :
Character(ID::player, GM, pos, hit, lf, dmg) {
    isWalking = false;
    totalTimeFromAttack = 0.0f;
    firstAttack = true;
    canJump = true;
    initializeSprite();
}

Player::~Player() {
}

/* Updates the position and velocity of player */
void Player::update(float dt) {

    if (life <= 0) 
        setShowing(false);
    
    if (isWalking)
        velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
    else
        velocity = Vector2f(velocity.x * 0.01f, velocity.y + GRAVITY * dt);

    if (velocity.y > 700)
        velocity = Vector2f(velocity.x, 700);

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));

    updateSprite(dt);
}

/* Render body to the screen */
void Player::render() {
    sprite->render();
}

/* Initialize the texture on the Animation */
void Player::initializeSprite() {
    sprite->initializeTexture(PLAYER_PATH, sf::Vector2u(4, 6));
}

/* Returns a row of the spritesheet of the character if can attack. */
int Player::canAttack(float dt) {
    if (isAttacking) {
        totalTimeFromAttack += dt;
        if (totalTimeFromAttack < attackTime) {
            if (firstAttack)
                return 4;
            else
                return 5;
        } else {
            firstAttack = !firstAttack;
            totalTimeFromAttack = 0;
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

/* Makes player jump */
void Player::jump() {
    if (canJump) {
        velocity = Vector2f(velocity.x, -sqrtf(2.0f * GRAVITY * PLAYER_JUMP));
        canJump = false;
    }
}

/* Update the Animation */
void Player::updateSprite(float dt) { 
    /* Attacking */
    if (canAttack() != 0)
        sprite->Update(canAttack(dt), dt, facingLeft(), position);
    /* Falling */
    else if (velocity.y > 150)
        sprite->Update(3, dt, facingLeft(), position);
    /* Jumping */
    else if (velocity.y < -100 && !canJump)
        sprite->Update(2, dt, facingLeft(), position);
    /* Walking */
    else if (abs(velocity.x) > 0.001)
        sprite->Update(1, dt, facingLeft(), position);
    /* Idle */
    else
        sprite->Update(0, dt, facingLeft(), position);
}