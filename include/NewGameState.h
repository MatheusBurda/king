#pragma once

#include "Menu.h"
#include "State.h"
#include "LevelMaker.h"
class InputManager;

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

namespace SM {

class Game;

class NewGameState : public Menu, public State {
private:
    Game* pGame;
    bool onePlayer;

public:
    NewGameState(InputManager* IM = NULL, Game* pG = NULL);
    ~NewGameState();

    void update();
    void render();
    void exec();
    void startNewLevel(bool isOnePLayer);
};

}
