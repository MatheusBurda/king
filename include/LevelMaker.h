#pragma once
#include "Level.h"


class LevelMaker{
private:
	Level* lvl;
    int numlvl;
public:
    LevelMaker(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize, int numlvl);
    ~LevelMaker();
    void buildPlatform(sf::Vector2f pos, const char path[100]);
    void setPlayer1(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildArcher(sf::Vector2f pos);
    void buildArcher(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildWall(sf::Vector2f pos, const char* path, bool faceLeft);
    void buildLava(sf::Vector2f pos);
    void buildWeb(sf::Vector2f pos);
    void setPlayer2(sf::Vector2f pos);
    void buildBoss(sf::Vector2f pos);
    void buildMap();
    Level* getLevel() { return lvl; }
    void loadMap();
};

