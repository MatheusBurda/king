#include "Player.h"

#include "Animation.h"
#include "EventManager.h"
#include <math.h>

const float Player::attackTime = 0.8;

Player::Player(const bool isPlayer1, InputManager* pIM) :
Character(ID::player, sf::Vector2f(0, 0), sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE),
player1(isPlayer1),
pc(pIM, this),
points(0) {
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

/* Initialize the texture on the Animation */
void Player::initializeSprite() {
    if(player1)
        sprite->initializeTexture(PLAYER_1_PATH, sf::Vector2u(4, 6));
    else{
        sprite->initializeTexture(PLAYER_2_PATH, sf::Vector2u(4, 6));
        pc.setKeys(sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::RControl);
    }

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

void Player::reset() {
    isWalking = false;
    totalTimeFromAttack = 0.0f;
    firstAttack = true;
    canJump = true;
    life = PLAYER_LIFE;
    setShowing(true);
    setVelocity(sf::Vector2f(0.0f, 0.0f));
    initializeSprite();
}

/* function to save the player in a txt */
void Player::save() {
    ofstream file;
    if (isPlayer1()) {
        file.open("./assets/Saves/Player1.txt");
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << (int)getPosition().x << ' ' << (int)getPosition().y - 30 << ' ' << points;
        file.close();
    } else {
        file.open("./assets/Saves/Player2.txt");
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << (int)getPosition().x << ' ' << (int)getPosition().y - 30 << ' ' << points;
        file.close();
    }
}

void Player::updatePoints(int pt) {
    points += pt;
}