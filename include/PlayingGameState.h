#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

class Level;

namespace SM {

class Game;

class PlayingGameState : public State {
private:
    Game* pGame;
    Level* pLevel;

public:
    PlayingGameState(InputManager* IM = NULL, Game* pG = NULL);
    ~PlayingGameState();

    void update(float dt);
    void render();
    void endLevel(bool lvlEnded);
};

}
