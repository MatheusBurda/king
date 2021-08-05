#pragma once
#include "Archer.h"
#include "Arrow.h"
#include "Background.h"
#include "CollisionManager.h"
#include "Entity.h"
#include "EntityList.h"
#include "EventManager.h"
#include "Fireball.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "Platform.h"
#include "Player.h"
#include "PlayerControl.h"
#include "Wall.h"
#include "Wizard.h"
#include "stdafx.h"

class Level {
protected:
    GraphicManager* graphicM;
    EntityList _list;
    Player *player1, *player2;
    CollisionManager colis;
    sf::Vector2u levelMapSize;
    Background back;
    EventManager* pEventManager;
    sf::Clock time;
    float dt;
    bool levelRunning;

public:
    Level(const char* path, sf::Vector2u levelSize = sf::Vector2u(0, 0));
    ~Level();
    void exec();

    GraphicManager* getGM() { return graphicM; }
    EntityList* getList() { return &_list; }
    Player* getP1() { return player1; }
    Player* getP2() { return player2; }
    void setP1(Player* p1) { player1 = p1; }
    void setP2(Player* p2) { player2 = p2; }
    CollisionManager getCols() { return colis; }
    void renderAll();
    bool isLevelRunning() const { return levelRunning; }
};
