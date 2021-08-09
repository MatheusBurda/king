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
#include "PauseMenu.h"
#include "StateMachine.h"
#include "NewGameState.h"

namespace SM {

class Game : public StateMachine {
private:
    GraphicManager* pGraphicM;
    EventManager* pEventM;
    InputManager* pInputM;
    MainMenuState* objMainMenuState;
    NewGameState* objNewGameState;
    Level* pLevel;
    Player* player1;
    Player* player2;
    EntityList* pEntityL;
    CollisionManager* pColisM;
    int currentLevel;

public:
    Game();
    ~Game();
    void exec();
    void startNewLevel();
    void save();
};

}
