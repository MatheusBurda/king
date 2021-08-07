#pragma once


#include "CastleBuilder.h"
#include "EventManager.h"
#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "MainMenu.h"
#include "MenuControl.h"
#include "PauseMenu.h"
#include "EntityList.h"
#include "LoadBuilder.h"

class Game {
private:
    GraphicManager* pGraphicM;
    EventManager* pEventM;
    InputManager* pInputM;
    MainMenu* objMainMenu;
    Level* pLevel;
    Player* player1;
    Player* player2;
    EntityList* pEntityL;
    CollisionManager* pColisM;
    int state;
    int currentLevel;

public:
    Game();
    ~Game();
    void exec();
    void startNewLevel();
    void save();
};
