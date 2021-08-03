#include "Menu.h"

#include "GraphicManager.h"
#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"

Menu::Menu(GraphicManager* GM) :
selected(0),
min(0),
max(2) {
    Button* bt = NULL;

    bt = new Button(GM, sf::Vector2f(600, 300));
    bt->setMessage("NEW GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(600, 450));
    bt->setMessage("LOAD GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(600, 600));
    bt->setMessage("EXIT");
    vectorOfButtons.push_back(bt);

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
