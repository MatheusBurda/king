#include "PauseMenu.h"

PauseMenu::PauseMenu(GraphicManager* GM, InputManager* IM):
Menu(GM, IM, BACKGROUND_PATH) {
    Button* bt = NULL;

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2 - 80));
    bt->setMessage("RESUME GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2));
    bt->setMessage("SAVE GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2 + 80));
    bt->setMessage("Exit TO Main MENU");
    vectorOfButtons.push_back(bt);

}

PauseMenu::~PauseMenu() {
}
