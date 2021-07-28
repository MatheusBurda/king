#include "CollisionManager.h"
#include "Enemy.h"
#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"

int main() {
    GraphicManager graphicM;

    EntityList _list;

    /*Testando Collision manager*/
    CollisionManager colis(&_list);

    Platform plat1(sf::Vector2f(00, 300), &graphicM);
    Platform plat3(sf::Vector2f(300, 400), &graphicM);
    Platform plat4(sf::Vector2f(400, 400), &graphicM);
    Enemy* etore = new Enemy(&graphicM);
    Platform plat2(sf::Vector2f(200, 400), &graphicM);
    Player Burda(&graphicM);

    sf::Clock time;
    float dt;

    _list.addEntity(&Burda);
    _list.addEntity(etore);

    _list.addEntity(&plat2);
    _list.addEntity(&plat1);
    _list.addEntity(&plat4);
    _list.addEntity(&plat3);

    /*-------------BACKGROUND TEMPOR�RIO-------------*/
    graphicM.setBackgroung("./assets/Backgrounds/montanha.png");
    graphicM.setPlayers(&Burda);
    graphicM.setEntityList(&_list);
    /*-------------------------------------------------*/
    
    time.restart();

    while (graphicM.isWindowOpen()) {
        dt = time.getElapsedTime().asSeconds();
        time.restart();

        _list.updateAll(dt);

        colis.toCollide();

        graphicM.exec();
    }

    return 0;
}