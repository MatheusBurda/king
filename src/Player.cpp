#include "Player.h"

#include "Animation.h"
#include "GraphicManager.h"
#include <math.h>

Player::Player(GraphicManager* GM) :
Character(ID::player, GM) {
    Canjump = true;
    life = PLAYER_LIFE;
    damage = PLAYER_DAMAGE;

    changePosition(sf::Vector2f(150, 20));

    setHitbox(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));

    initializeSprite();
}

Player::~Player() {
}

void Player::update(float dt) {

    velocity = Vector2f(velocity.x * 0.05f, velocity.y + GRAVITY * dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity = Vector2f(PLAYER_VELOCITY, velocity.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity = Vector2f(-PLAYER_VELOCITY, velocity.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Canjump) {
        velocity = Vector2f(velocity.x, -sqrtf(2.0f * GRAVITY * PLAYER_JUMP));
        Canjump = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!getIsAttacking())
            setIsAttacking(true);

    }

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    
    if(isAttacking)
        sprite->Update(5, dt, facingLeft(), position);
    /* Walking */
    else if (abs(velocity.x) < 0.001)
        sprite->Update(0, dt, facingLeft(), position);
    /* Idle */
    else
        sprite->Update(1, dt, facingLeft(), position);
}

void Player::render() {
    sprite->render();
}

void Player::initializeSprite() {
    sprite->initializeTexture(PLAYER_PATH, id, sf::Vector2u(4, 6));
}