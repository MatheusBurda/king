#include "LevelMaker.h"
LevelMaker::LevelMaker() { }

LevelMaker::~LevelMaker() {
}

void LevelMaker::buildPlatform(sf::Vector2f pos, const char path[100]) {
    Platform* plat = new Platform(ID::platform, pos, sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT), path);
    lvl->addEntity(plat);
}

void LevelMaker::setPlayer1(sf::Vector2f pos) {
    lvl->getP1()->changePosition(pos);
}

void LevelMaker::setPlayer2(sf::Vector2f pos) {
    if (lvl->getP2())
        lvl->getP2()->changePosition(pos);
}

void LevelMaker::buildWizard(sf::Vector2f pos) {
    Fireball* fb = new Fireball(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    lvl->addEntity(fb);
    lvl->addEntity(wi);
}

void LevelMaker::buildWizard(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing) {
    Fireball* fb = new Fireball(ID::fireball, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Wizard* wi = new Wizard(ID::wizard, pos, sf::Vector2f(WIZARD_WIDTH, WIZARD_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, fb);
    lvl->addEntity(fb);
    lvl->addEntity(wi);
    fb->setShowing(showing);
    fb->setVelocity(velProj);
    fb->changePosition(posProj);
}

void LevelMaker::buildArcher(sf::Vector2f pos) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    lvl->addEntity(ar);
    lvl->addEntity(arc);
}

void LevelMaker::buildArcher(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing) {
    Arrow* ar = new Arrow(ID::arrow, pos, sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
    Archer* arc = new Archer(ID::archer, pos, sf::Vector2f(ARCHER_WIDTH, ARCHER_HEIGHT), ENEMY_LIFE, ENEMY_DAMAGE, ar);
    lvl->addEntity(ar);
    lvl->addEntity(arc);
    ar->setShowing(showing);
    ar->setVelocity(velProj);
    ar->changePosition(posProj);
}

void LevelMaker::buildBoss(sf::Vector2f pos) {
    Boss* boss = new Boss(ID::boss, pos, sf::Vector2f(BOSS_WIDTH, BOSS_HEIGHT), BOSS_LIFE, BOSS_DMG);
    lvl->addEntity(boss);
}

void LevelMaker::buildWall(sf::Vector2f pos, const char* path, bool faceLeft) {
    Wall* wall = new Wall(ID::wall, pos, sf::Vector2f(WALL_WIDTH, WALL_HEIGHT), path);
    wall->setFacingLeft(faceLeft);
    lvl->addEntity(wall);
}

void LevelMaker::buildLava(sf::Vector2f pos) {
    Lava* lava = new Lava(ID::lava, pos, sf::Vector2f(LAVA_WIDTH, LAVA_HEIGHT));
    lvl->addEntity(lava);
}

void LevelMaker::buildWeb(sf::Vector2f pos) {
    SpiderWeb* web = new SpiderWeb(ID::spiderweb, pos, sf::Vector2f(SPIDER_WIDTH, SPIDER_HEIGHT));
    lvl->addEntity(web);
}

Level* LevelMaker::buildMap(const char* path, Player* p1, Player* p2, int numlvl) {
    int y = 30, x = 120;
    char level[30][120];
    srand(time(NULL));
    ifstream file;
    char platPath[100];
    char wallPath[100];
    if (numlvl <= 1) {
        file.open("./assets/Levels/Field.txt");
        lvl = new Level(PATH_BACKGROUND_FIELD, p1, p2, sf::Vector2u(120 * PLATFORM_WIDTH, 40 * PLATFORM_HEIGHT));
        strcpy(platPath, PLATFORM_PATH_DIRT);
        strcpy(wallPath, WALL_PATH_DIRT);
    } else if (numlvl == 2) {
        file.open("./assets/Levels/Castle.txt");
        lvl = new Level(PATH_BACKGROUND_CASTLE, p1, p2, sf::Vector2u(120 * PLATFORM_WIDTH, 40 * PLATFORM_HEIGHT));
        strcpy(platPath, PLATFORM_PATH_BRICK);
        strcpy(wallPath, WALL_PATH_BRICK);
    }
    if (!file) {
        cout << "Cant Open txt on buildMap" << endl;
        std::exit(54);
    }

    file >> level[0][0];
    while (!file.eof()) {
        file.ignore();
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (i || j)
                    file >> level[i][j];
                if (level[i][j] == 'p') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), platPath);
                } else if (level[i][j] == '1') {
                    setPlayer1(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'L') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), wallPath, true);
                } else if (level[i][j] == 'R') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), wallPath, false);
                } else if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == '2') {
                    setPlayer2(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'v') {
                    buildLava(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'w') {
                    buildWeb(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 's') {
                    int random = rand() % 10;
                    if (random >= 5)
                        buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'c') {
                    int random = rand() % 10;
                    if (random >= 5)
                        buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'q') {
                    int random = rand() % 10;
                    if (random >= 5)
                        buildWeb(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'n') {
                    int random = rand() % 10;
                    if (random >= 5)
                        buildLava(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'b') {
                    buildBoss(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                } else if (level[i][j] == 'e') {
                    lvl->setEnd(j * PLATFORM_WIDTH);
                }
            }
        }
    }
    strcpy(platPath, "");
    strcpy(wallPath, "");
    file.close();
    return lvl;
}

Level* LevelMaker::loadMap(Player* p1, Player* p2) {
    char path[100];
    int end;
    ifstream Leveltxt("./assets/Saves/Level.txt", ios::in);
    if (!Leveltxt) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }

    Leveltxt >> path >> end;
    Leveltxt.close();

    lvl = new Level(path, p1, p2, sf::Vector2u(120 * PLATFORM_WIDTH, 40 * PLATFORM_HEIGHT));

    lvl->setEnd(end);
    if (!path) {
        cout << "No level saved" << endl;
        exit(99);
    }

    sf::Vector2f pos;
    bool facingLeft;
    bool showing;
    sf::Vector2f posProj;
    sf::Vector2f velProj;
    ifstream Player1(("./assets/Saves/Player1.txt"), ios::in);
    if (!Player1) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    Player1 >> pos.x >> pos.y >> facingLeft;
    setPlayer1(sf::Vector2f(pos.x, pos.y));
    Player1.close();

    ifstream Platform(("./assets/Saves/Platform.txt"), ios::in);
    if (!Platform) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (Platform >> pos.x >> pos.y >> path)
        buildPlatform(sf::Vector2f(pos.x, pos.y), path);
    Platform.close();

    ifstream Wall(("./assets/Saves/Wall.txt"), ios::in);
    if (!Wall) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (Wall >> pos.x >> pos.y >> path >> facingLeft)
        buildWall(sf::Vector2f(pos.x, pos.y), path, facingLeft);
    Wall.close();

    ifstream Lava(("./assets/Saves/Lava.txt"), ios::in);
    if (!Lava) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (Lava >> pos.x >> pos.y)
        buildLava(sf::Vector2f(pos.x, pos.y));
    Lava.close();
    ifstream SpiderWeb(("./assets/Saves/SpiderWeb.txt"), ios::in);
    if (!SpiderWeb) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (SpiderWeb >> pos.x >> pos.y)
        buildWeb(sf::Vector2f(pos.x, pos.y));
    SpiderWeb.close();

    ifstream Archer("./assets/Saves/Archer.txt");
    if (!Archer) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (Archer >> pos.x >> pos.y >> posProj.x >> posProj.y >> velProj.x >> velProj.y >> showing)
        buildArcher(sf::Vector2f(pos.x, pos.y), sf::Vector2f(posProj.x, posProj.y), sf::Vector2f(velProj.x, velProj.y), showing);
    Archer.close();

    ifstream Wizard("./assets/Saves/Wizard.txt");
    if (!Wizard) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    while (Wizard >> pos.x >> pos.y >> posProj.x >> posProj.y >> velProj.x >> velProj.y >> showing)
        buildWizard(sf::Vector2f(pos.x, pos.y), sf::Vector2f(posProj.x, posProj.y), sf::Vector2f(velProj.x, velProj.y), showing);
    Wizard.close();

    ifstream Boss("./assets/Saves/Boss.txt");
    if (!Boss) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    Boss >> pos.x >> pos.y;
    buildBoss(sf::Vector2f(pos.x, pos.y));
    Boss.close();

    return lvl;
}