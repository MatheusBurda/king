#include "GraphicManager.h"

GraphicManager::GraphicManager() {
}

GraphicManager::~GraphicManager() {
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