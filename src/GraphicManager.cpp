#include "GraphicManager.h"

GraphicManager::GraphicManager() :
    window(sf::VideoMode(800, 600), "king++") {
}

GraphicManager::~GraphicManager() {
}

sf::RenderWindow* GraphicManager::getWindow() {
    return &window;
}

void GraphicManager::display() {
    window.display();
}

void GraphicManager::clear() {
    window.clear();
}

bool GraphicManager::isWindowOpen() {
    return window.isOpen();
}
