#include "GraphicManager.h"

GraphicManager::GraphicManager() :
    window(new sf::RenderWindow(sf::VideoMode(800, 600), "king++")) {
}

GraphicManager::~GraphicManager() {
    delete (window);
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
