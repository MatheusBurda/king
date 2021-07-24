#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"

int main() {
    GraphicManager graphicM;

    EntityList _list;

    Platform ground(sf::Vector2f(150.f,150.f));

    Player Burda;
    Entity Dalpra;
    sf::Clock time;
    float dt;

    Dalpra.setWindow(graphicM.getWindow());
    Burda.setWindow(graphicM.getWindow());
    ground.setWindow(graphicM.getWindow());

    _list.addEntity(&Burda);
    _list.addEntity(&Dalpra);
    _list.addEntity(&ground);


    while (graphicM.isWindowOpen()) {
        dt = time.getElapsedTime().asSeconds();
        /* cout << dt << endl; */
        time.restart();
        graphicM.clear();

        _list.updateAll(dt);

        _list.renderAll();

        graphicM.display();
    }

    return 0;
}