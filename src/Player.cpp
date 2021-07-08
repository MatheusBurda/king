#include "Player.h"

Player::Player() {
	id = ID::player;
    setHitbox(Vector2f(50, 50));
    body.setSize(hitbox);
    body.setFillColor(Color::Blue);
    body.setPosition(Vector2f(100, 200));
}

void Player::update() {
    Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            body.move(10.f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            body.move(-10.f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            body.move(0.f, -10.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            body.move(0.f, 10.0f);
        }
    }
    render();
}

void Player::render() {
    window->draw(body);
}