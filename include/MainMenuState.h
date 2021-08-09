#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

namespace SM {

class MainMenuState : public Menu, public State {
private:
public:
    MainMenuState(InputManager* IM = NULL, StateMachine* pSM = NULL);
    ~MainMenuState();

    void update();
    void render();
    void exec();
};

}
