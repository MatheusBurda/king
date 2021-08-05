#include "Level.h"

Level::Level(const char* path, sf::Vector2u levelSize) :
graphicM(GraphicManager::getInstance()),
_list(),
player1(NULL),
player2(NULL),
colis(&_list),
levelMapSize(levelSize),
back(sf::Vector2f(float(graphicM->getWindowSize().x / 2), float(graphicM->getWindowSize().y / 2)), path) {
    pEventManager = EventManager::getInstance();
    time.restart();
    levelRunning = true;
}

Level::~Level() {
    _list.deleteAll();
}

void Level::exec() {
    if (player1->getShowing()) {
        /* Get the elapsed time from last loop */
        dt = time.getElapsedTime().asSeconds();
        time.restart();
        /* Update all entities */
        _list.updateAll(dt);
        /* Collide all entities */
        colis.toCollide();
    }
    else
        levelRunning = false;
}

/* Run all graphic events */
void Level::renderAll() {
    sf::Vector2f viewPosition;
    if (player2 == NULL) {
        viewPosition = player1->getPosition();
    } else {
        viewPosition = (player1->getPosition() + player2->getPosition()) / 2.0f;
    }
    graphicM->centerView(viewPosition);

    //back.render();
    /* Alterar */
    back.changePos(player1->getPosition());

    for (int i = 0; i < _list.getSize(); i++) {
        _list[i]->render();
    }
}
