#include "InputManager.h"

#include "Observer.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

/* Subscribe a Observer to recieve a notification when something happens. */
void InputManager::subscribe(Observer* pObserver) {
    objObserving.push_back(pObserver);
}

/* Check for keys pressed and notify every Observer. */
void InputManager::exec() {
    if (sf::Event::KeyPressed) {
        cout << "tecla pressionada!!!!" << endl;
    }
}
