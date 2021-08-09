#include "State.h"

#include "StateMachine.h"

using namespace SM;

State::State(StateMachine* pSM) :
pSM(pSM) { }

State::~State() {
    pSM = NULL;

}

void State::setStateMachine(StateMachine* pSM) {
    this->pSM = pSM;
}

void State::changeState(SM::stateID id) {
    pSM->changeCurrentState(id);
}
