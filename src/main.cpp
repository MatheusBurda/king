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
    Dalpra.setWindow(graphicM.getWindow());
    Burda.setWindow(graphicM.getWindow());

    //Dalpra.setPosition(sf::Vector2f(200.f, 100.f));

    _list.addEntity(&Burda);
    _list.addEntity(&Dalpra);

    while (graphicM.isWindowOpen()) {
        graphicM.clear();
        
        _list.updateAll();
        _list.renderAll();

        graphicM.display();
    }

    return 0;
}