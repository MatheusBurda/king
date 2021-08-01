#include "Observer.h"

Observer::Observer(InputManager* pIM) {
    this->pIM = pIM;
    pIM->subscribe(this);
}
