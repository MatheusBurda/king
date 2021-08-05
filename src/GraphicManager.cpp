#include "GraphicManager.h"

/* Singleton design pattern - Only one instance will be created */

GraphicManager* GraphicManager::instance = NULL;

/* Returns a pointer to the GraphicManager. */
GraphicManager* GraphicManager::getInstance() {
    if (instance == NULL) {
        instance = new GraphicManager();
    }
    return instance;
}

GraphicManager::GraphicManager() :
window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "king++")),
view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
texturesMap() {
    window->setFramerateLimit(FRAME_RATE);
}

/* ========================================= */

GraphicManager::~GraphicManager() {
    std::map<const char*, sf::Texture*>::iterator it;
    for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
        delete (it->second);

    delete (window);
}

/* Give a pointer to a body and it will be drawn to the screen. */
void GraphicManager::render(sf::RectangleShape* body) {
    window->draw(*body);
}

/* Give a pointer to a Text and it will be drawn to the screen */
void GraphicManager::render(sf::Text* text) {
    window->draw(*text);
}

/* Display everything that was drawn. */
void GraphicManager::display() {
    window->display();
}

/* Clear the window to re-display stuff. */
void GraphicManager::clear() {
    window->clear();
}

/* Returns pointer to the window. */
sf::RenderWindow* GraphicManager::getWindow() const {
    return window;
}

/* Returns if the window is open. */
bool GraphicManager::isWindowOpen() const {
    return window->isOpen();
}

/* CAUTION: Call the close window function - SFML window will close. */
void GraphicManager::closeWindow() {
    window->close();
}

/* Handles  resize. */
void GraphicManager::handleWindowResize() {
    float aspectRatio = float(window->getSize().x / float(window->getSize().y));
    view.setSize(sf::Vector2f(HEIGHT * aspectRatio, HEIGHT));
    window->setView(view);
}

/* Returns the window size. */
sf::Vector2u GraphicManager::getWindowSize() const {
    return window->getSize();
}

/* Changes the view position. */
void GraphicManager::centerView(sf::Vector2f pos) {
    view.setCenter(pos);
    window->setView(view);
}

/* Returns a texture to be used by an entity. */
sf::Texture* GraphicManager::loadTexture(const char* path) {
    /* Tries to find an existing texture linked by the id. */
    std::map<const char*, sf::Texture*>::iterator it;
    it = texturesMap.find(path);
    if (it != texturesMap.end()) {
        return it->second;
    }

    /* If not found, have to load it. */
    sf::Texture* tex = new sf::Texture();

    if (!tex->loadFromFile(path)) {
        cout << "ERROR loading file " << path << endl;
        exit(1);
    }
    texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

    return tex;
}
