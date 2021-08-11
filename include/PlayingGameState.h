#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;
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
    void resetState();
    void endLevel(bool lvlEnded);
};

}
