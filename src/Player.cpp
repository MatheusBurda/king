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
            velocity = Vector2f(10, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity = Vector2f(-10, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity = Vector2f(velocity.x, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity = Vector2f(velocity.x, 10);
        }
        time2 = clock();
        if ((time2 - time1) >= 10) {
            velocity = Vector2f(velocity.x, velocity.y + 1);
            time1 = clock();
            time2 = clock();

        }
        body.move(velocity);
    }


}

void Player::render() {
   
    window->draw(body);
}