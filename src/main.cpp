#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"


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

    Platform ground(sf::Vector2f(00,200), &graphicM);
    Platform plat2(sf::Vector2f(200,200), &graphicM);
    Player Burda(&graphicM);

    sf::Clock time;
    float dt;

    _list.addEntity(&Burda);
    _list.addEntity(&ground);
    _list.addEntity(&plat2);

    while (graphicM.isWindowOpen()) {

        dt = time.getElapsedTime().asSeconds();

        time.restart();
        
        graphicM.clear();

        graphicM.checkWindowEvents();

        Burda.colliding(&plat2);
        Burda.colliding(&ground);

        //DESENHANDO BACKGROUND
        graphicM.getWindow()->draw(background);

        _list.updateAll(dt);

        _list.renderAll();

        graphicM.display();
    }

    return 0;
}