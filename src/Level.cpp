#include "Level.h"

void Level::exec() {
    pc.addPlayer(player1);
    sf::Clock time;
    float dt;
    time.restart();
    while (graphicM.isWindowOpen() && player1->getShowing()) { //&& player2->getShowing()) {
        pEventManager->pollEvents();

        dt = time.getElapsedTime().asSeconds();
        time.restart();
        _list.updateAll(dt);
        colis.toCollide();
        graphicM.exec();
    }
    cout << "Morri" << endl;
}

Level::Level() :
graphicM(),
_list(),
player1(NULL),
player2(NULL),
colis(&_list),
im(),
pc(&im) {
    player1 = NULL;
    player2 = NULL;

    pEventManager = EventManager::getInstance();
    pEventManager->setGraphicManager(&graphicM);
    pEventManager->setInputManager(&im);
}

Level::~Level() {
    _list.deleteAll();
}
