#pragma once

#include "EntityList.h"
#include "EventManager.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "LoadGameState.h"
#include "MainMenuState.h"
#include "MenuControl.h"
#include "NewGameState.h"
#include "PauseMenuState.h"
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
    sf::Clock time;

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
    bool isTwoPlayersActive() const;

    int getCurrentLevel() const;
    void setCurrentLevel(int num);

    void endGame();
    void deleteLevel();
    void resetPlayers();
};

}
