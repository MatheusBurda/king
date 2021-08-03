#include "CastleBuilder.h"
CastleBuilder::CastleBuilder() :LevelBuilder() {
    castle = new Level("./assets/Backgrounds/bck1.png");
    buildMap();
}

CastleBuilder::~CastleBuilder() {

}

void CastleBuilder::buildMap() {
    int y = 15, x = 60;
    char level[15][60];
    std::ifstream file("./assets/Levels/Castle.txt");
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
                    buildPlatform(sf::Vector2f(j * 30, i * 30), castle, PLATFORM_PATH1);
                }
                if (level[i][j] == 'c') {
                    buildPlatform(sf::Vector2f(j * 30, i * 30), castle, PLATFORM_PATH2);
                }
                if (level[i][j] == 'k' && !castle->getP1()) {
                    buildPlayer1(sf::Vector2f(j * 30, i * 30), castle);
                }
                if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * 30, i * 30), castle);
                }
                if (level[i][j] == 'w') {
                    buildWall(sf::Vector2f(j * 30, i * 30), castle);
                }
                if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * 30, i * 30), castle);
                }
            }
        }
    }
    file.close();
}