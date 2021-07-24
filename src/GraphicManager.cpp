#include "GraphicManager.h"

GraphicManager::GraphicManager() :
window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "king++")),
pEntityList(NULL) {
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(FRAME_RATE);
}

GraphicManager::~GraphicManager() {
    delete (window);
}

void GraphicManager::setEntityList(EntityList* pList) {
    pEntityList = pList;
}

sf::RenderWindow* GraphicManager::getWindow() {
    return window;
}

void GraphicManager::display() {
    window->display();
}

void GraphicManager::clear() {
    window->clear();
}

bool GraphicManager::isWindowOpen() {
    return window->isOpen();
}
