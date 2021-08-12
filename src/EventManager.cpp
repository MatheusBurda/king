#include "EventManager.h"

/* Singleton design pattern - Only one instance will be created */
EventManager* EventManager::instance = NULL;

EventManager* EventManager::getInstance() {
    if (instance == NULL) {
        instance = new EventManager();
    }
    return instance;
}

EventManager::EventManager() :
pGraphicM(NULL),
pInputM(NULL),
pWindow(NULL) {
    setGraphicManager();
}

/* ========================================= */

EventManager::~EventManager() {
    if (pInputM)
        delete (pInputM);
    pGraphicM = NULL;
    pInputM = NULL;
    pWindow = NULL;
}

void EventManager::setGraphicManager() {
    pGraphicM = GraphicManager::getInstance();
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
        if ((event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) && pInputM)
            pInputM->handleKeyPressed();
       /*  if (event.type == sf::Event::TextEntered)
            pInputM->handleTextEntered(event); */
    }
}
