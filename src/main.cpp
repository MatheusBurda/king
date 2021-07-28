#include "CollisionManager.h"
#include "Enemy.h"
#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "stdafx.h"
#include "Fireball.h"
int main() {
    GraphicManager graphicM;

    EntityList _list;

    /*Testando Collision manager*/
    CollisionManager colis(&_list);

    Fireball* fb = new Fireball(ID::fireball, &graphicM, sf::Vector2f(300.0f, 300.0f), sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Enemy* etore = new Enemy(ID::enemy,&graphicM, sf::Vector2f(300.0f, 300.0f), sf::Vector2f(ENEMY_WIDTH,ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    Player Burda(ID::player, &graphicM, sf::Vector2f(500.0f, 300.0f), sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);

    sf::Clock time;
    float dt;

    _list.addEntity(&Burda);
    _list.addEntity(fb);
    _list.addEntity(etore);


    Platform plat1(ID::platform, &graphicM, sf::Vector2f(100.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat2(ID::platform, &graphicM, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat3(ID::platform, &graphicM, sf::Vector2f(300.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat4(ID::platform, &graphicM, sf::Vector2f(400.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat5(ID::platform, &graphicM, sf::Vector2f(500.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat6(ID::platform, &graphicM, sf::Vector2f(600.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat7(ID::platform, &graphicM, sf::Vector2f(700.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat8(ID::platform, &graphicM, sf::Vector2f(800.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat9(ID::platform, &graphicM, sf::Vector2f(900.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat10(ID::platform, &graphicM, sf::Vector2f(1000.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    Platform plat11(ID::platform, &graphicM, sf::Vector2f(1100.0f, 400.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    
    _list.addEntity(&plat1);
    _list.addEntity(&plat2);
    _list.addEntity(&plat3);
    _list.addEntity(&plat4);
    _list.addEntity(&plat5);
    _list.addEntity(&plat6);
    _list.addEntity(&plat7);
    _list.addEntity(&plat8);
    _list.addEntity(&plat9);
    _list.addEntity(&plat10);
    _list.addEntity(&plat11);


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