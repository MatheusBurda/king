#pragma once

#include "CastleBuilder.h"
#include "EntityList.h"
#include "EventManager.h"
#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "LoadBuilder.h"
#include "MainMenuState.h"
#include "MenuControl.h"
#include "NewGameState.h"
#include "PauseMenu.h"
#include "PlayingGameState.h"
#include "StateMachine.h"

namespace SM {

class Game : public StateMachine {
private:
    GraphicManager* pGraphicM;
    EventManager* pEventM;
    InputManager* pInputM;
    Level* pLevel;
    Player* player1;
    Player* player2;
    int currentLevel;

public:
    Game();
    ~Game();

    void startStates();

    void exec();
    void save();

    Level* getpLevel() const;
    void setLevel(Level* pLevel);

    Player* getPLayer1();
    Player* getPLayer2();

    int getCurrentLevel() const;
    void setCurrentLevel(int num);
};

}
