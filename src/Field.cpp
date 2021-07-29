#include "Field.h"

Field::Field():
    Level(){
    graphicM.setEntityList(&_list);
    graphicM.setBackground("./assets/Backgrounds/montanha.png");
    createPlayer();
    createEnemy();
    createPlatform();
    exec();
}
Field:: ~Field() {
    _list.deleteAll();
}
void Field::createPlayer() {

    Player* pl = new Player(ID::player, &graphicM, sf::Vector2f(600.0f, 300.0f), sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    _list.addEntity(pl);
    player1 = pl;
    /*Player* pl2 = new Player(ID::player, &graphicM, sf::Vector2f(700.0f, 300.0f), sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    _list.addEntity(pl2);
    player2 = pl2;*/
    graphicM.setPlayers(pl);
}
void Field::createEnemy() {
    int i;
    for (i = 0; i < 4; i++) {
        Fireball* fb = new Fireball(ID::fireball, &graphicM, sf::Vector2f(300.0f, 00.0f), sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
        Enemy* en = new Enemy(ID::enemy, &graphicM, sf::Vector2f(50*i, 200.0f), sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
        _list.addEntity(fb);
        _list.addEntity(en);
    }
}
void Field::createPlatform() {
    int i;
    for (i = 0; i < 10; i++) {
        Platform* plat = new Platform(ID::platform, &graphicM, sf::Vector2f(120 * i, 300.0f), sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
        _list.addEntity(plat);
    }
}