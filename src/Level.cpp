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
void Level::buildWizard(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing) {
    Fireball* fb = new Fireball(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    this->getList()->addEntity(fb);
    this->getList()->addEntity(wi);
    fb->setShowing(showing);
    fb->setVelocity(velProj);
    fb->changePosition(posProj);
}

void Level::buildArcher(sf::Vector2f pos) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    this->getList()->addEntity(ar);
    this->getList()->addEntity(arc);
}
void Level::buildArcher(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    this->getList()->addEntity(ar);
    this->getList()->addEntity(arc);
    ar->setShowing(showing);
    ar->setVelocity(velProj);
    ar->changePosition(posProj);
}
void Level::buildBoss(sf::Vector2f pos) {
    Boss* boss = new Boss(ID::boss, pos, sf::Vector2f(BOSS_WIDTH, BOSS_HEIGHT), BOSS_LIFE, BOSS_DMG);
    this->getList()->addEntity(boss);
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
    clean.open("./assets/Saves/Wall.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Player2.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Platform.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/SpiderWeb.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Lava.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Boss.txt", ios::trunc);
    clean.close();
    for (int i = 0; i < _list->getSize(); i++) {
            (*_list)[i]->save();
    }
}
void Level::buildMap() {
    int y = 40, x = 120;
    char level[40][120];
    ifstream file;
    if (numlvl == 1)
        file.open("./assets/Levels/Field.txt");
    else if (numlvl == 2)
        file.open("./assets/Levels/Castle.txt");

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
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), PLATFORM_PATH_DIRT);
                }
                else if (level[i][j] == 'x') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), PLATFORM_PATH_COBBLE);
                }
                else if (level[i][j] == '1') {
                    setPlayer1(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'L') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), WALL_PATH_DIRT, false);
                }
                else if (level[i][j] == 'R') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), WALL_PATH_DIRT, true);
                }
                else if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == '2') {
                    setPlayer2(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'v') {
                    buildLava(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'w') {
                    buildWeb(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 's') {
                    int i = rand() % 10;
                    if (i >= 5)
                        buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'c') {
                    int i = rand() % 10;
                    if (i >= 5)
                        buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'q') {
                    int i = rand() % 10;
                    if (i >= 5)
                        buildWeb(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'n') {
                    int i = rand() % 10;
                    if (i >= 5)
                        buildLava(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'b') {
                    buildBoss(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
            }
        }
    }
    file.close();
}