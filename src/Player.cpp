#include "Player.h"

Player::Player() {
    life = PLAYER_LIFE;
    damage = PLAYER_DAMAGE;
    id = ID::player;
    setHitbox(Vector2f(50, 50));
    body.setSize(hitbox);
    body.setFillColor(Color::Blue);
    body.setPosition(Vector2f(100, 200));
}

void Player::update(float dt) {
    Event event;

    velocity = Vector2f(0, velocity.y + GRAVITY * dt);

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity = Vector2f(PLAYER_VELOCITY, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity = Vector2f(-PLAYER_VELOCITY, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity = Vector2f(velocity.x, 0);
        }
    }
    changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
    body.setPosition(position);
}

void Player::render() {

    window->draw(body);
}
