#include "Player.h"

#include "GraphicManager.h"

Player::Player(GraphicManager* GM) :
Character(ID::player, GM) {
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

    velocity = Vector2f(0, velocity.y + GRAVITY * dt);
    /* velocity = Vector2f(0, 0); */


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity = Vector2f(PLAYER_VELOCITY, velocity.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity = Vector2f(-PLAYER_VELOCITY, velocity.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity = Vector2f(velocity.x, 0);
    }

    if (stopy)
        velocity.y = 0;
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    body.setPosition(position);
}

void Player::render() {
    pGraphicManager->centerView(position);
    pGraphicManager->getWindow()->draw(body);
}

void Player ::colliding(Entity* ent) {
    if (ent->getId() == 0) {

    } else if (ent->getId() == ID::plataform) {
        if ((getPosition().y + PLAYER_HEIGHT <= ent->getPosition().y + 10 && getPosition().y + PLAYER_HEIGHT >= ent->getPosition().y - 10) && (getPosition().x + PLAYER_WIDTH / 2 >= ent->getPosition().x && getPosition().x + PLAYER_WIDTH / 2 <= ent->getPosition().x + PLATFORM_WIDTH)) {
            stopy = true;
        } else {
            stopx = false;
            stopy = false;
        }
    } else {
        stopx = false;
        stopy = false;
    }
}