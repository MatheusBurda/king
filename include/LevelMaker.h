#pragma once
#include "Level.h"

#define PATH_BACKGROUND_FIELD "./assets/Backgrounds/montanha.png"
#define PATH_BACKGROUND_CASTLE "./assets/Backgrounds/montanha.png"

class LevelMaker {
private:
    Level* lvl;

    void buildPlatform(sf::Vector2f pos, const char path[100]);
    void setPlayer1(sf::Vector2f pos);
    void setPlayer2(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildArcher(sf::Vector2f pos);
    void buildArcher(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildWall(sf::Vector2f pos, const char* path, bool faceLeft);
    void buildLava(sf::Vector2f pos);
    void buildWeb(sf::Vector2f pos);
    void buildBoss(sf::Vector2f pos);

public:
    LevelMaker();
    ~LevelMaker();
    Level* buildMap(const char* path, Player* p1, Player* p2, int numlvl);
    Level* loadMap(Player* p1, Player* p2);
};
