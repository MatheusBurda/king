#include "Level.h"

Level::Level(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
graphicM(GraphicManager::getInstance()),
_list(new EntityList()),
player1(p1),
player2(p2),
colis(_list),
levelMapSize(levelSize),
back(sf::Vector2f(float(graphicM->getWindowSize().x / 2), float(graphicM->getWindowSize().y / 2)), path),
numlvl(-1) {
    pEventManager = EventManager::getInstance();
    time.restart();
    levelRunning = true;

    if (player1) {

        _list->addEntity(player1);
    }
    if (player2) {

        _list->addEntity(player2);
    }
}

Level::~Level() {
    if (player1) {
        _list->removeEntity(player1);
    }
    if (player2) {
        _list->removeEntity(player2);
    }
    _list->deleteAll();
    delete (_list);
}

void Level::exec() {
    if (player1->getShowing()) {
        /* Get the elapsed time from last loop */
        dt = time.getElapsedTime().asSeconds();
        time.restart();
        /* Update all entities */
        _list->updateAll(dt);
        /* Collide all entities */
        colis.toCollide();
    } else
        levelRunning = false;
}

/* Run all graphic events */
void Level::renderAll() {
    sf::Vector2f viewPosition;
    if (player2 == NULL) {
        viewPosition = player1->getPosition();
    } else {
        viewPosition = (player1->getPosition() + player2->getPosition()) / 2.0f;
    }
    graphicM->centerView(viewPosition);

    //back.render();
    /* Alterar */
    back.changePos(player1->getPosition());

    for (int i = 0; i < _list->getSize(); i++) {
        if ((*_list)[i]->getShowing())
            (*_list)[i]->render();
    }
}

void Level::buildPlatform(sf::Vector2f pos, const char path[100]) {
    Platform* plat = new Platform(ID::platform, pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT), path);
    this->getList()->addEntity(plat);
}

void Level::setPlayer1(sf::Vector2f pos) {
    player1->changePosition(pos);

}
void Level::setPlayer2(sf::Vector2f pos) {
    player2->changePosition(pos);

}

void Level::buildWizard(sf::Vector2f pos) {
    Fireball* fb = new Fireball(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    this->getList()->addEntity(fb);
    this->getList()->addEntity(wi);
}

void Level::buildArcher(sf::Vector2f pos) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    this->getList()->addEntity(ar);
    this->getList()->addEntity(arc);
}

void Level::buildWall(sf::Vector2f pos, const char* path, bool faceLeft) {
    Wall* wall = new Wall(ID::wall, pos, sf::Vector2f(WALL_WIDTH, WALL_HEIGHT), path);
    wall->setFacingLeft(faceLeft);
    this->getList()->addEntity(wall);
}
void Level::buildLava(sf::Vector2f pos) {
    Lava* lava = new Lava(ID::lava, pos, sf::Vector2f(LAVA_WIDTH, LAVA_HEIGHT));
    this->getList()->addEntity(lava);
}
void Level::buildWeb(sf::Vector2f pos) {
    SpiderWeb* web = new SpiderWeb(ID::spiderweb, pos, sf::Vector2f(SPIDER_WIDTH, SPIDER_HEIGHT));
    this->getList()->addEntity(web);
}
void Level::saveLvl() {
    ofstream level;
    level.open("./assets/Saves/Level.txt", ios::trunc);
    if (!level) {
        cout << "ERROR TO OPEN FILE" << endl;
        abort();
    }
    level << numlvl;
    level.close();
    ofstream clean;
    clean.open("./assets/Saves/Player1.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Wizard.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Archer.txt", ios::trunc);
    clean.close();
    for (int i = 0; i < _list->getSize(); i++) {
        if ((*_list)[i]->getID() == ID::player || (*_list)[i]->getID() == ID::player2 || (*_list)[i]->getID() == ID::archer || (*_list)[i]->getID() == ID::wizard || (*_list)[i]->getID() == ID::boss)
            (static_cast<Character*>((*_list)[i]))->save();
    }
}