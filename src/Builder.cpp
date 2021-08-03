#include "Builder.h"
void Builder::buildPlatform(sf::Vector2f pos, Level* lvl, char path[100]) {
    Platform* plat = new Platform(ID::platform, (lvl->getGM()), pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT), path);
    lvl->getList()->addEntity(plat);
}
void Builder::buildPlayer1(sf::Vector2f pos, Level* lvl) {
    Player* pl = new Player(ID::player, (lvl->getGM()), pos, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    lvl->getList()->addEntity(pl);
    lvl->setP1(pl);
    lvl->getGM()->setPlayers(pl);
}
void Builder::buildWizard(sf::Vector2f pos, Level* lvl) {
    Fireball* fb = new Fireball(ID::fireball, (lvl->getGM()), pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, (lvl->getGM()), pos, sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    lvl->getList()->addEntity(fb);
    lvl->getList()->addEntity(wi);
}
void Builder::buildArcher(sf::Vector2f pos, Level* lvl) {
    Arrow* ar = new Arrow(ID::arrow, (lvl->getGM()), pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, (lvl->getGM()), pos, sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    lvl->getList()->addEntity(ar);
    lvl->getList()->addEntity(arc);
}
void Builder::buildWall(sf::Vector2f pos, Level* lvl) {
    Wall* wall = new Wall(ID::wall, (lvl->getGM()), pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
    lvl->getList()->addEntity(wall);
}
