#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

namespace SM {

class NewGameState : public Menu, public State {
private:
    sf::String playerInput;
    sf::Text playerText;
    sf::Font font;

public:
    NewGameState(InputManager* IM = NULL, StateMachine* pSM = NULL);
    ~NewGameState();

    void update();
    void render();
    void exec();
};

}
