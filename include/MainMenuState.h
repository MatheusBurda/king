#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

namespace SM {

class Game;

class MainMenuState : public Menu, public State {
private:
    Game* pGame;

public:
    MainMenuState(InputManager* IM = NULL, Game* pG = NULL);
    ~MainMenuState();

    void update(float dt);
    void render();
    void resetState();
    void exec();
};

}
