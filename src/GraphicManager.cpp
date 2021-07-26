#include "GraphicManager.h"

GraphicManager::GraphicManager() :
window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "king++")),
view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
pEntityList(NULL) {
    window->setFramerateLimit(FRAME_RATE);
}

GraphicManager::~GraphicManager() {

    std::map<ID::ids, sf::Texture*>::iterator it;
    for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
        delete (it->second);

    delete (window);
}

/* Sets the entity list to be iterated through */
void GraphicManager::setEntityList(EntityList* pList) {
    pEntityList = pList;
}

/* Returns pointer to the window */
sf::RenderWindow* GraphicManager::getWindow() const {
    return window;
}

/* Display everything that was drawn */
void GraphicManager::display() {
    window->display();
}

/* Clear the window to re-display stuff */
void GraphicManager::clear() {
    window->clear();
}

/* Returns if the window is open */
bool GraphicManager::isWindowOpen() const {
    return window->isOpen();
}

/* Checks Events from the window, such as resize */
void GraphicManager::checkWindowEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::Resized) {
            view.setSize(sf::Vector2f(event.size.width, event.size.height));
            window->setView(view);
        }
    }
}

/* Changes the view position */
void GraphicManager::centerView(const sf::Vector2f center) {
    view.setCenter(center);
/*     view.move(center); */
    window->setView(view);
}

/* Returns a texture to be used by an entity */
sf::Texture* GraphicManager::loadTexture(ID::ids id, const char* path) {
    /* Tries to find an existing texture linked by the id */
    std::map<ID::ids, sf::Texture*>::iterator it;
    it = texturesMap.find(id);
    if (it != texturesMap.end()) {
        return it->second;
    }

    /* If not found, have to load it */
    sf::Texture* tex = new sf::Texture();

    if (!tex->loadFromFile(path)) {
        cout << "ERROR loading file " << path << endl;
        exit(1);
    }
    texturesMap.insert(std::pair<ID::ids, sf::Texture*>(id, tex));

    return tex;
}
