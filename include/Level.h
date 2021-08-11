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
#include "Lava.h"
#include "Platform.h"
#include "Player.h"
#include "PlayerControl.h"
#include "SpiderWeb.h"
#include "Wall.h"
#include "Wizard.h"
#include "stdafx.h"
#include "Boss.h"
class Level {
protected:
    GraphicManager* graphicM;
    EntityList* _list;
    Player *player1, *player2;
    CollisionManager colis;
    sf::Vector2u levelMapSize;
    Background back;
    EventManager* pEventManager;
    bool levelRunning;
    char path[100];
    int reachEnd;

public:
    Level(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize);
    virtual ~Level();
    void exec(float dt);

    GraphicManager* getGM() { return graphicM; }
    EntityList* getList() { return _list; }
    Player* getP1() { return player1; }
    Player* getP2() { return player2; }
    void setP1(Player* p1) { player1 = p1; }
    void setP2(Player* p2) { player2 = p2; }
    CollisionManager* getCols() { return &colis; }
    void renderAll();
    bool isLevelRunning() const { return levelRunning; }
    void addEntity(Entity* ent) { _list->addEntity(ent); }
    //function used to save the Level in a txt
    virtual void saveLvl();
    void setEnd(int end) { reachEnd = end; }
};
