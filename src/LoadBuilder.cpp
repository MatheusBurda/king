#include "LoadBuilder.h"
LoadBuilder::LoadBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
	Level(path,p1, p2, levelSize){
    buildMap();
}
LoadBuilder::~LoadBuilder() {
    saveLvl();
    _list->removeEntity(player1);
    _list->deleteAll();
}
void LoadBuilder::buildMap() {
    ifstream Level("./assets/Saves/Level.txt", ios::in);
    if (!Level) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    Level >> numlvl;

    ifstream file;
    if (numlvl == -1) {
        cout << "No level saved" << endl;
        exit(99);
    }
    else if(numlvl ==1 )
    file.open("./assets/Levels/Field.txt");
    else
    file.open("./assets/Levels/Castle.txt");

    int y = 40, x = 120;
    char level[40][120];

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
                else if (level[i][j] == 'c') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), PLATFORM_PATH_COBBLE);
                }
                else if (level[i][j] == 'L') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), WALL_PATH_DIRT, false);
                }
                else if (level[i][j] == 'R') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH + (PLATFORM_WIDTH - WALL_WIDTH) / 2, i * WALL_HEIGHT), WALL_PATH_DIRT, true);
                }
                else if (level[i][j] == 'v') {
                    buildLava(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
                else if (level[i][j] == 'w') {
                    buildWeb(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
            }
        }
    }

    file.close();

    sf::Vector2f pos;
    bool facingLeft;
    ifstream Player1(("./assets/Saves/Player1.txt"), ios::in);
    if (!Player1) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    Player1 >> pos.x >> pos.y >> facingLeft;
    setPlayer1(sf::Vector2f(pos.x, pos.y));
    Player1.close();

    ifstream Archer("./assets/Saves/Archer.txt");
    if (!Archer) {
        cout << "Cant Open" << endl;
        return;
    }
    while (Archer >> pos.x >> pos.y >> facingLeft)
        buildArcher(sf::Vector2f(pos.x, pos.y));
    Archer.close();

    ifstream Wizard("./assets/Saves/Wizard.txt");
    if (!Wizard) {
        cout << "Cant Open" << endl;
        return;
    }
    while (Wizard >> pos.x >> pos.y >> facingLeft)
        buildWizard(sf::Vector2f(pos.x, pos.y));
    Wizard.close();
}
