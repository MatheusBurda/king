#include "Menu.h"

#include "GraphicManager.h"

Menu::Menu(GraphicManager* GM) :
bt1(GM, sf::Vector2f(600, 300)),
bt2(GM, sf::Vector2f(600, 450)),
bt3(GM, sf::Vector2f(600, 600)),
selected(1),
min(1),
max(3) {
    bt1.setMessage("NEW GAME");
    bt2.setMessage("LOAD GAME");
    bt3.setMessage("EXIT");
    exec();
}

Menu::~Menu() {
}

void Menu::render() {
    bt1.render();
    bt2.render();
    bt3.render();
}

void Menu::exec() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        selected++;
        if (selected > max)
            selected = max;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        selected--;
        if (selected < min)
            selected = min;
    }

    bt1.select(selected == 1);
    bt2.select(selected == 2);
    bt3.select(selected == 3);
}
