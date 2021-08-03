#include "InputManager.h"

#include "Observer.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

/* Check for keys pressed and notify every Observer. */
void InputManager::handleKeyPressed() {
    cout << "tecla pressionada! " << endl;
    for (it = objObserving.begin(); it != objObserving.end(); ++it)
        (*it)->notify();
}

/* Subscribe a Observer to recieve a notification when something happens. */
void InputManager::registerObserver(Observer* pObserver) {
    objObserving.push_back(pObserver);
}

void InputManager::removeObserver(Observer* pObserver) {
    objObserving.remove(pObserver);
}