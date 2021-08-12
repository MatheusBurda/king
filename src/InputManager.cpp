#include "InputManager.h"

#include "Observer.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
    objObserving.clear();
}

/* Check for keys pressed and notify every Observer. */
void InputManager::handleKeyPressed() {
    for (it = objObserving.begin(); it != objObserving.end(); ++it)
        (*it)->notify();
}

/* Subscribe a Observer to recieve a notification when something happens. */
void InputManager::Attach(Observer* pObserver) {
    objObserving.push_back(pObserver);
}

void InputManager::Detach(Observer* pObserver) {
    objObserving.remove(pObserver);
}

void InputManager::handleTextEntered(sf::Event eventCopy) {
    if (eventCopy.key.code == 8) {
        currentTextString = "";
    } else
        currentTextString += eventCopy.text.unicode;
}

sf::String InputManager::getString() {
    return currentTextString;
}

void InputManager::deleteString() {
    currentTextString.clear();
}
