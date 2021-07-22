#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Player.h"
#include "stdafx.h"

int main() {
    GraphicManager graphicM;

    EntityList _list;

    Player Burda;
    Entity Dalpra;
    sf:: Clock time;
    float dt;
    
    Dalpra.setWindow(graphicM.getWindow());
    Burda.setWindow(graphicM.getWindow());

    _list.addEntity(&Burda);
    _list.addEntity(&Dalpra);

    while (graphicM.isWindowOpen()) {
        dt = time.getElapsedTime().asSeconds();
        graphicM.clear();

        _list.updateAll(dt);

        _list.renderAll();

        graphicM.display();
    }

    return 0;
}