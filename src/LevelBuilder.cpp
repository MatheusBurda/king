#include "LevelBuilder.h"

void LevelBuilder::buildPlatform(sf::Vector2f pos, Level* lvl, const char path[100]) {
    Platform* plat = new Platform(ID::platform, pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT), path);
    lvl->getList()->addEntity(plat);
}

void LevelBuilder::buildPlayer1(sf::Vector2f pos, Level* lvl) {
    Player* pl = new Player(ID::player, pos, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_LIFE, PLAYER_DAMAGE);
    lvl->getList()->addEntity(pl);
    lvl->setP1(pl);
}

void LevelBuilder::buildWizard(sf::Vector2f pos, Level* lvl) {
    Fireball* fb = new Fireball(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    lvl->getList()->addEntity(fb);
    lvl->getList()->addEntity(wi);
}

void LevelBuilder::buildArcher(sf::Vector2f pos, Level* lvl) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    lvl->getList()->addEntity(ar);
    lvl->getList()->addEntity(arc);
}

void LevelBuilder::buildWall(sf::Vector2f pos, Level* lvl, const char* path, bool faceLeft) {
    Wall* wall = new Wall(ID::wall, pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT), path);
    wall->setFacingLeft(faceLeft);
    lvl->getList()->addEntity(wall);
}
