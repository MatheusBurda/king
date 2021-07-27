#include "Player.h"

#include "GraphicManager.h"
#include <math.h>

Player::Player(GraphicManager* GM) :
Character(ID::player, GM) {
    Canjump = true;
    life = PLAYER_LIFE;
    damage = PLAYER_DAMAGE;
    setHitbox(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    body.setOrigin(hitbox / 2.0f);
    body.setSize(hitbox);
    changePosition(sf::Vector2f(150, 20));

    sf::Texture* tex;
    tex = pGraphicManager->loadTexture(ID::player, PLAYER_PATH);
    body.setTexture(tex);
}

Player::~Player() {
}

void Player::update(float dt) {

    velocity = Vector2f(velocity.x * 0.5f, velocity.y + GRAVITY * dt);

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
        setIsAttacking(true);
    }

    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    body.setPosition(position);
}

void Player::render() {
    pGraphicManager->centerView(position);
    pGraphicManager->getWindow()->draw(body);
}
