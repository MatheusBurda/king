#include "Level.h"

void Level::exec() {

    pc.addPlayer(player1);

    sf::Clock time;
    float dt;
    time.restart();
    while (graphicM.isWindowOpen() && player1->getShowing()) { //&& player2->getShowing()) {

        im.exec();

        dt = time.getElapsedTime().asSeconds();
        time.restart();
        _list.updateAll(dt);
        colis.toCollide();
        graphicM.exec();
    }
    cout << "Morri" << endl;
}

Level::Level() :
colis(&_list),
im(),
pc(&im) {
    player1 = NULL;
    player2 = NULL;
}

Level::~Level() {
    _list.deleteAll();
}
