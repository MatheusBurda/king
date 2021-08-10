#pragma once

#include "stdafx.h"
#include "State.h"
#include <vector>

namespace SM {

class StateMachine {
protected:
    std::vector<State*> vectorOfStates;
    SM::stateID currentStateID; 

public:
    StateMachine();
    virtual ~StateMachine();

    void changeCurrentState(SM::stateID id);
    void execCurrentState(float dt);
    stateID getCurrentState() const;
};

}