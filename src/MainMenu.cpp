#include "MainMenu.h"

MainMenu::MainMenu(GraphicManager* GM, InputManager* IM) :
Menu(GM, IM, BACKGROUND_MAIN_MENU) {
    Button* bt = NULL;

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2));
    bt->setMessage("NEW GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2 + 80));
    bt->setMessage("LOAD GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2 + 160));
    bt->setMessage("LEADERBOARD");
    vectorOfButtons.push_back(bt);

    bt = new Button(GM, sf::Vector2f(GM->getWindow()->getSize().x / 2.0f, GM->getWindow()->getSize().y / 2 + 240));
    bt->setMessage("QUIT GAME");
    vectorOfButtons.push_back(bt);

    max = 3;
}

MainMenu::~MainMenu() {
}
