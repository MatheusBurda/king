#pragma once
#include "Being.h"
class Player :public Being
{
public:
	Player();
	void update() {
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
	void render() {
        window->draw(body);
	}
};

