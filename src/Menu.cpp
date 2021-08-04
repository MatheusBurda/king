#include "Menu.h"

#include "GraphicManager.h"

Menu::Menu(GraphicManager* GM, InputManager* IM, const char* backPath) :
selected(0),
min(0),
max(2),
control(IM, this),
back(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2), backPath) {

    
}

Menu::~Menu() {
    Button* bt = NULL;
    while (vectorOfButtons.size() != 0) {
        bt = vectorOfButtons.back();
        delete (bt);
        vectorOfButtons.pop_back();
    }
    vectorOfButtons.clear();
}

/* Menu operation to render all it's objects. */
void Menu::render() {
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

/* Exec the function of the button selected */
int Menu::exec() {
    return selected;
}

/* Make the menu selection go Down */
void Menu::selectDown() {
    vectorOfButtons[selected]->select(false);
    selected++;
    if (selected > max)
        selected = max;
    vectorOfButtons[selected]->select(true);
}

/* Make the menu selection go Up */
void Menu::selectUp() {
    vectorOfButtons[selected]->select(false);
    selected--;
    if (selected < min)
        selected = min;
    vectorOfButtons[selected]->select(true);
}
