#pragma once

#include "LevelMaker.h"
#include "State.h"

class InputManager;

#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"

namespace SM {

class Game;

class LoadGameState : public State {
private:
    Game* pGame;

public:
    LoadGameState(InputManager* IM = NULL, Game* pG = NULL);
    ~LoadGameState();

    void update(float dt);
    void render();
    void resetState();
};

}
