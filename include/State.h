#pragma once

#include "stdafx.h"

namespace SM {

class StateMachine;

enum stateID {
    mainMenu = 0,
    newGame,
    playing,
    exit,
    loadGame,
    pauseMenu,
    saveGame,
    leaderboard
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