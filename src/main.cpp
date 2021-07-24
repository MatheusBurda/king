#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"


int main() {
    GraphicManager graphicM;

    EntityList _list;

    /*-------------BACKGROUND TEMPORÁRIO-------------*/
    sf::Texture textureback;
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setPosition(0, 0);
    if (!textureback.loadFromFile("./assets/Backgrounds/background1.jpg")) {
        exit(9);
    }
    background.setTexture(&textureback);

    /*-------------------------------------------------*/

    Platform ground(sf::Vector2f(50,100));
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
        Burda.colliding(&ground);
        //DESENHANDO BACKGROUND
        graphicM.getWindow()->draw(background);

        _list.updateAll(dt);

        _list.renderAll();

        graphicM.display();
    }

    return 0;
}