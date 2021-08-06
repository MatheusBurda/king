#include "BossBuilder.h"
BossBuilder::BossBuilder() {
	boss = new Level("./assets/Backgrounds/boss1.png");
	buildMap();
}
BossBuilder::~BossBuilder() {

}
void BossBuilder::buildMap() {
    int y = 15, x = 60;
    char level[15][60];
    std::ifstream file("./assets/Levels/Boss.txt");
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
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss, PLATFORM_PATH_COBBLE);
                }
                if (level[i][j] == 'c') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss, PLATFORM_PATH_BRICK);
                }
                if (level[i][j] == 'k' && !boss->getP1()) {
                    buildPlayer1(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss);
                }
                if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss);
                }
                if (level[i][j] == 'w') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss, WALL_PATH_COBBLE, true);
                }
                if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), boss);
                }
            }
        }
    }
    file.close();
}
