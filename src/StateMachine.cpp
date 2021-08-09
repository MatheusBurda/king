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

void StateMachine::execCurrentState() {
    vectorOfStates[currentStateID]->update();
    vectorOfStates[currentStateID]->render();
}