#include "StateMachine.h"

#include "State.h"

using namespace SM;

StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
    State* st = NULL;
    while (vectorOfStates.size() != 0) {
        st = vectorOfStates.back();
        delete (st);
        vectorOfStates.pop_back();
    }
    vectorOfStates.clear();
}

void StateMachine::changeCurrentState(SM::stateID id) {
    currentStateID = id;
}

void StateMachine::execCurrentState(float dt) {
    vectorOfStates[currentStateID]->update(dt);
    vectorOfStates[currentStateID]->render();
}

stateID StateMachine::getCurrentState() const {
    return currentStateID;
}