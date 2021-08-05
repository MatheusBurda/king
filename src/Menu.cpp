#include "Menu.h"

#include "GraphicManager.h"

Menu::Menu(InputManager* IM, const char* backPath) :
selected(0),
min(0),
max(2),
control(IM, this),
back(sf::Vector2f(0, 0), backPath) {
    GraphicManager* GM = GraphicManager::getInstance();
    back.changePos(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
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

/* Exec the function of the button selected */
void Menu::exec() {
    *pState = selected;
}

/* Menu operation to render all it's objects. */
void Menu::render() {
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
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

/* Set stateManager to change states */
void Menu::setPState(int* p){
    pState = p;
}