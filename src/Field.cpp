#include "Field.h"

Field::Field() :
Level() {
    graphicM.setEntityList(&_list);
    graphicM.setBackground("./assets/Backgrounds/montanha.png");
    createLevel();
    exec();
}

Field::~Field() {
    _list.deleteAll();
}

void Field::createPlayer(sf::Vector2f pos) {

    Player* pl = new Player(ID::player, &graphicM, pos, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    _list.addEntity(pl);
    player1 = pl;
    /*Player* pl2 = new Player(ID::player, &graphicM, sf::Vector2f(650.0f, 300.0f), sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    _list.addEntity(pl2);
    player2 = pl2;*/
    graphicM.setPlayers(pl);
}

void Field::createEnemy(sf::Vector2f pos) {
    Fireball* fb = new Fireball(ID::fireball, &graphicM, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Enemy* en = new Enemy(ID::enemy, &graphicM, pos, sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    _list.addEntity(fb);
    _list.addEntity(en);
}

void Field::createPlatform(sf::Vector2f pos) {
    Platform* plat = new Platform(ID::platform, &graphicM, pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    _list.addEntity(plat);
}

void Field::createLevel() {
    int y = 14, x = 60;
    char level[14][60];
    std::ifstream file("./assets/Levels/Field.txt");
    if (!file) {
        cout << "Cant Open" << endl;
        return;
    }
    file >> level[0][0];
    while (!file.eof()) {
        file.ignore();
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (i || j)
                    file >> level[i][j];
                if (level[i][j] == 'p') {
                    createPlatform(sf::Vector2f(j * 120, i * 120));
                }
                if (level[i][j] == 'k') {
                    createPlayer(sf::Vector2f(j * 120, i * 120));
                }
                if (level[i][j] == 'e') {
                    createEnemy(sf::Vector2f(j * 120, i * 120));
                }
            }
        }
    }
    file.close();
}