#include "Player.h"

Player::Player(): life(100), damage(25) {
    id = ID::player;
    setHitbox(Vector2f(50, 50));
    body.setSize(hitbox);
    body.setFillColor(Color::Blue);
    body.setPosition(Vector2f(100, 200));
}

void Player::update(float dt) {
    Event event;

     velocity = Vector2f(velocity.x,  9.8*dt);

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity = Vector2f(5, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity = Vector2f(-5, velocity.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity = Vector2f(velocity.x, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity = Vector2f(velocity.x, 5);
        }

        changePosition(Vector2f(velocity.x*dt + position.x, velocity.y*dt + position.y));
        body.setPosition(position);
    }



}

void Player::render() {
   
    window->draw(body);
}

//
int Player::attack() {
    return damage;
}
void Player::getHurt(int enemydmg) {
    life -= enemydmg;
}
bool Player::amAlive() {
    if (life > 0)
        return true;
    return false;
}
