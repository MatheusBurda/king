#include "FieldBuilder.h"


FieldBuilder::FieldBuilder(const char* path, EntityList* EL, Player* p1, Player* p2, CollisionManager* CM, sf::Vector2u levelSize) :
    Level(path, EL, p1, p2, CM, levelSize){
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
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), PLATFORM_PATH_DIRT);
                }else if (level[i][j] == 'c') {
                    buildPlatform(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT),PLATFORM_PATH_COBBLE);
                }else if (level[i][j] == 'k' && !existsP1) {
                    setPlayer1(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }else if (level[i][j] == 'z') {
                    buildWizard(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }else if (level[i][j] == 'L') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT), WALL_PATH_DIRT, false);
                }else if (level[i][j] == 'R') {
                    buildWall(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT),  WALL_PATH_DIRT, true);
                }else if (level[i][j] == 'a') {
                    buildArcher(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }else if (level[i][j] == 'q' && !existsP2) {
                    setPlayer2(sf::Vector2f(j * PLATFORM_WIDTH, i * WALL_HEIGHT));
                }
            }
        }
    }
    file.close();
}