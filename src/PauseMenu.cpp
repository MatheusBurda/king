#include "PauseMenu.h"

PauseMenu::PauseMenu(InputManager* IM) :
Menu(IM, BACKGROUND_PATH) {
    GraphicManager* GM = GraphicManager::getInstance();

    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 - 80));
    bt->setMessage("RESUME GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
    bt->setMessage("SAVE GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("Exit TO Main MENU");
    vectorOfButtons.push_back(bt);
}

PauseMenu::~PauseMenu() {
}
