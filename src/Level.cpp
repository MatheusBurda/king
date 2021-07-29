#include "Level.h"

void Level::exec() {
    sf::Clock time;
    float dt;
    time.restart();
    while (graphicM.isWindowOpen() && player1->getShowing()) { //&& player2->getShowing()) {
        dt = time.getElapsedTime().asSeconds();
        time.restart();
        _list.updateAll(dt);
        colis.toCollide();
        graphicM.exec();
    }
    cout << "Morri" << endl;
}

Level::Level() :
colis(&_list) {
    player1 = NULL;
    player2 = NULL;
}

Level::~Level() {
    _list.deleteAll();
}

