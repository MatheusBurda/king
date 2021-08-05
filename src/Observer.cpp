#include "Observer.h"

Observer::Observer(InputManager* pIM) {
    this->pIM = pIM;
    pIM->Attach(this);
}

Observer::~Observer(){
    pIM->Detach(this);
    pIM = NULL;
}