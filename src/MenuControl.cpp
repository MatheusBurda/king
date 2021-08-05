#include "MenuControl.h"

#include "InputManager.h"
#include "Menu.h"

MenuControl::MenuControl(InputManager* pIM, Menu* pM) :
Observer(pIM),
pMenu(pM) { }

MenuControl::~MenuControl() {
    pMenu = NULL;
}

void MenuControl::notify() {

    if (pMenu == NULL) {
        cout << "ERROR pointer to Menu NULL on MenuControl::notify()." << endl;
        exit(7);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        pMenu->selectDown();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        pMenu->selectUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        pMenu->exec();
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        pMenu->selectDown(); */
}

void MenuControl::addMenu(Menu* p) {
    pMenu = p;
}
