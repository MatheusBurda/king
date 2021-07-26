#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"
#include"CollisionManager.h"

int main() {
    GraphicManager graphicM;

    EntityList _list;

    /*-------------BACKGROUND TEMPOR�RIO-------------*/
    sf::Texture textureback;
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setPosition(0, 0);
    if (!textureback.loadFromFile("./assets/Backgrounds/montanha.png")) {
        exit(9);
    }
    background.setTexture(&textureback);

    /*-------------------------------------------------*/
    /*Testando Collision manager*/
    CollisionManager colis;




    Platform plat1(sf::Vector2f(00,200), &graphicM);
    Platform plat2(sf::Vector2f(200,400), &graphicM);
    Platform plat3(sf::Vector2f(300, 400), &graphicM);
    Player Burda(&graphicM);

    sf::Clock time;
    float dt;

    _list.addEntity(&Burda);

    _list.addEntity(&plat2);
    _list.addEntity(&plat3);
    time.restart();
    while (graphicM.isWindowOpen()) {
        dt = time.getElapsedTime().asSeconds();
        time.restart();

        
        graphicM.clear();

        graphicM.checkWindowEvents();
   
 

        //DESENHANDO BACKGROUND
        graphicM.getWindow()->draw(background);

        _list.updateAll(dt);
    
        colis.toCollide(&Burda, &plat2);
        colis.toCollide(&Burda, &plat3);
        _list.renderAll();

        graphicM.display();
    }

    return 0;
}