#include "GraphicManager.h"

GraphicManager::GraphicManager() :
window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "king++")),
view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
texturesMap(),
backgroundTexture(NULL),
backgroundBody(sf::Vector2f(WIDTH, HEIGHT)),
pEntityList(NULL),
player1(NULL),
player2(NULL) {
    window->setFramerateLimit(FRAME_RATE);
}

GraphicManager::~GraphicManager() {

    delete (backgroundTexture);

    std::map<ID::ids, sf::Texture*>::iterator it;
    for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
        delete (it->second);

    delete (window);
}

/* Does everything to clear and draw everything to screen */
void GraphicManager::exec() {
    clear();

    renderAll();

    display();
}

/* Render all entities from the EntityList */
void GraphicManager::renderAll() {
    Entity* pAux;
    for (int i = 0; i < pEntityList->getSize(); i++) {
        if ((*pEntityList)[i]->getShowing()) {
            pAux = (*pEntityList)[i];
            pAux->render();
        }
    }
}

/* Give a pointer to a body and it will be drawn to the screen. */
void GraphicManager::render(sf::RectangleShape* body) {
    window->draw(*body);
}

/* Sets the entity list to be iterated through. */
void GraphicManager::setEntityList(EntityList* pList) {
    pEntityList = pList;
}

/* Returns pointer to the window. */
sf::RenderWindow* GraphicManager::getWindow() const {
    return window;
}

/* Display everything that was drawn. */
void GraphicManager::display() {
    window->display();
}

/* Clear the window to re-display stuff. */
void GraphicManager::clear() {
    window->clear();
    centerView();
    updateBackground();
    window->draw(backgroundBody);
}

/* Returns if the window is open. */
bool GraphicManager::isWindowOpen() const {
    return window->isOpen();
}

void GraphicManager::closeWindow() {
    window->close();
}

/* Handles  resize. */
void GraphicManager::handleWindowResize() {
    float aspectRatio = float(window->getSize().x / float(window->getSize().y));
    view.setSize(sf::Vector2f(HEIGHT * aspectRatio, HEIGHT));
}

/* Changes the view position. */
void GraphicManager::centerView() {

    if (player2 == NULL) {
        view.setCenter(player1->getPosition());
    } else {
        view.setCenter((player1->getPosition() + player2->getPosition()) / 2.0f);
    }

    window->setView(view);
}

/* Returns a texture to be used by an entity. */
sf::Texture* GraphicManager::loadTexture(ID::ids id, const char* path) {
    /* Tries to find an existing texture linked by the id. */
    std::map<ID::ids, sf::Texture*>::iterator it;
    it = texturesMap.find(id);
    if (it != texturesMap.end()) {
        return it->second;
    }

    /* If not found, have to load it. */
    sf::Texture* tex = new sf::Texture();

    if (!tex->loadFromFile(path)) {
        cout << "ERROR loading file " << path << endl;
        exit(1);
    }
    texturesMap.insert(std::pair<ID::ids, sf::Texture*>(id, tex));

    return tex;
}

/* Set the player pointers to set the view position later on. */
void GraphicManager::setPlayers(Player* player1, Player* player2) {
    if (player1 == NULL) {
        cout << "ERROR: player is NULL on GraphicManager::setPlayers." << endl;
        exit(7);
    }
    this->player1 = player1;
    this->player2 = player2;
}

/* Set the background from path. */
void GraphicManager::setBackground(const char* path) {
    if (backgroundTexture != NULL)
        delete (backgroundTexture);

    backgroundTexture = new Texture();

    if (!backgroundTexture->loadFromFile(path)) {
        exit(9);
    }
    backgroundBody.setSize(sf::Vector2f(backgroundTexture->getSize()));
    backgroundBody.scale(sf::Vector2f(5, 5));
    backgroundBody.setTexture(backgroundTexture);
    backgroundBody.setOrigin(backgroundBody.getSize() / 2.0f);
    //cout << "Background set to " << backgroundBody.getSize().x << " | " << backgroundBody.getSize().y << endl;
}

/* Update Background position to be centered on the view. */
void GraphicManager::updateBackground() {
    backgroundBody.setPosition(view.getCenter());
}
