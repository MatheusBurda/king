#include "Observer.h"

Observer::Observer(InputManager* pIM) {
    this->pIM = pIM;
    pIM->registerObserver(this);
}

Observer::~Observer(){
    pIM->removeObserver(this);
    pIM = NULL;
}