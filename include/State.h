#pragma once

#include "stdafx.h"

namespace SM {

class StateMachine;

enum stateID {
    mainMenu = 0,
    newGame = 1,
    loadGame = 2,
    playing = 3,
    pauseMenu = 4,
    saveGame = 5,
    leaderboard = 6,
    exit = 7
};

class State {

private:
    StateMachine* pSM;

public:
    State(StateMachine* pSM = NULL);
    virtual ~State();

    void setStateMachine(StateMachine* pSM);
    void changeState(SM::stateID id);
    virtual void update() = 0;
    virtual void render() = 0;
};

}