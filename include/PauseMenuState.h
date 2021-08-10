#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;

#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"

namespace SM {

class Game;

class PauseMenuState : public Menu, public State {
private:
    Game* pGame;

public:
    PauseMenuState(InputManager* IM = NULL, Game* pG = NULL);
    ~PauseMenuState();

    void update(float dt);
    void render();
    void exec();
};

}
