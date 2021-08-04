#include "FieldBuilder.h"


FieldBuilder::FieldBuilder():LevelBuilder(){
    field = new Level("./assets/Backgrounds/montanha.png");
    buildMap();
}

FieldBuilder::~FieldBuilder() {

}

void FieldBuilder:: buildMap() {
    int y = 40, x = 120;
    char level[40][120];
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
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field, PLATFORM_PATH_DIRT);
                }
                if (level[i][j] == 'c') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field, PLATFORM_PATH_COBBLE);
                }
                if (level[i][j] == 'k' && !field->getP1()) {
                    buildPlayer1(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field);
                }
                if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field);
                }
                if (level[i][j] == 'L') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field, WALL_PATH_DIRT, false);
                }
                if (level[i][j] == 'R') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field, WALL_PATH_DIRT, true);
                }
                if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * PLATFORM_HEIGHT), field);
                }
            }
        }
    }
    file.close();
}