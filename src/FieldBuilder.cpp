#include "FieldBuilder.h"
FieldBuilder::FieldBuilder():Builder(){
    field = new Field();
    buildMap();
}

FieldBuilder::~FieldBuilder() {

}

void FieldBuilder::buildPlayer1(sf::Vector2f pos) {
    Player* pl = new Player(ID::player, (field->getGM()), pos, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    field->getList()->addEntity(pl);
    field->setP1(pl);
    field->getGM()->setPlayers(pl);
}

void FieldBuilder::buildEnemy(sf::Vector2f pos) {
    Fireball* fb = new Fireball(ID::fireball, (field->getGM()), pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Enemy* en = new Enemy(ID::enemy, (field->getGM()), pos, sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    field->getList()->addEntity(fb);
    field->getList()->addEntity(en);
}

void FieldBuilder::buildPlatform(sf::Vector2f pos) {
    Platform* plat = new Platform(ID::platform, (field->getGM()), pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    field->getList()->addEntity(plat);
}
void FieldBuilder::buildWall(sf::Vector2f pos) {
    Wall* wall = new Wall(ID::wall, (field->getGM()), pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    field->getList()->addEntity(wall);
}
void FieldBuilder:: buildMap() {
    int y = 15, x = 60;
    char level[15][60];
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
                    buildPlatform(sf::Vector2f(j * 30, i * 30));
                }
                if (level[i][j] == 'k' && !field->getP1()) {
                    buildPlayer1(sf::Vector2f(j * 30, i * 30));
                }
                if (level[i][j] == 'e') {
                    buildEnemy(sf::Vector2f(j * 30, i * 30));
                }
                if (level[i][j] == 'w') {
                    buildWall(sf::Vector2f(j * 30, i * 30));
                }
            }
        }
    }
    file.close();
}