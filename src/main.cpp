
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "king++");
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::Red);
    sf::Vector2f position(500.0f, 50.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shape.move(10.f, 0.0f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shape.move(-10.f, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shape.move(0.f, -10.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shape.move(0.f, 10.0f);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}