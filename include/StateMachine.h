#pragma once

#include "stdafx.h"
#include "State.h"
#include <vector>
#include <map>

namespace SM {

class StateMachine {
protected:
    std::vector<State*> vectorOfStates;
    std::map<int id, State*> mapStates;
    SM::stateID currentStateID; 

public:
    StateMachine();
    virtual ~StateMachine();

    void changeCurrentState(SM::stateID id);
    void execCurrentState(float dt);
    stateID getCurrentState() const;
};

}