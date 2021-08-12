#pragma once

#include "Archer.h"
#include "Arrow.h"
#include "Background.h"
#include "Boss.h"
#include "CollisionManager.h"
#include "Entity.h"
#include "EntityList.h"
#include "EventManager.h"
#include "Fireball.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "Lava.h"
#include "Level.h"
#include "Platform.h"
#include "Player.h"
#include "PlayerControl.h"
#include "SpiderWeb.h"
#include "Wall.h"
#include "Wizard.h"
#include "stdafx.h"

class LevelMaker {
private:
    Level* lvl;

    void buildPlatform(sf::Vector2f pos, int type);
    void setPlayer1(sf::Vector2f pos);
    void setPlayer2(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos);
    void buildWizard(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildArcher(sf::Vector2f pos);
    void buildArcher(sf::Vector2f pos, sf::Vector2f posProj, sf::Vector2f velProj, bool showing);
    void buildWall(sf::Vector2f pos, int type, bool faceLeft);
    void buildLava(sf::Vector2f pos);
    void buildWeb(sf::Vector2f pos);
    void buildBoss(sf::Vector2f pos);

public:
    LevelMaker();
    ~LevelMaker();
    Level* buildMap(const char* path, Player* p1, Player* p2, int numlvl);
    Level* loadMap(Player* p1, Player* p2);
};
