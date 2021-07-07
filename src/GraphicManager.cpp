#include "GraphicManager.h"

GraphicManager::GraphicManager() {
}

GraphicManager::~GraphicManager() {
}

sf::RenderWindow* GraphicManager::getWindow() {
}

void GraphicManager::display() {
    window->display();
}

void GraphicManager::clear() {
    window->clear();
}