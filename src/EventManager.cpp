#include "EventManager.h"

EventManager::EventManager(GraphicManager* pGM, InputManager* pIM) :
pGraphicM(pGM),
pInputM(pIM),
pWindow(NULL) {
    if (pGraphicM != NULL)
        pWindow = pGraphicM->getWindow();
}

EventManager::~EventManager() {
}

void EventManager::setGraphicManager(GraphicManager* pGM) {
    pGraphicM = pGM;
    if (pGraphicM != NULL)
        pWindow = pGraphicM->getWindow();
}

void EventManager::setInputManager(InputManager* pIM) {
    pInputM = pIM;
}

void EventManager::pollEvents() {
    sf::Event event;

    while (pWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            pGraphicM->closeWindow();
        if (event.type == sf::Event::Resized)
            pGraphicM->handleWindowResize();
        if (event.type == sf::Event::KeyPressed) 
            pInputM->handleKeyPressed();
    }
}
