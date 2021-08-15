#pragma once

#include "Background.h"
#include "CollisionManager.h"
#include "Entity.h"
#include "EntityList.h"
#include "EventManager.h"
#include "GraphicManager.h"
#include "Player.h"
#include "stdafx.h"

#define PATH_BACKGROUND_FIELD "./assets/Backgrounds/field.png"
#define PATH_BACKGROUND_CASTLE "./assets/Backgrounds/Castle.png"

class Level {
private:
    GraphicManager* graphicM;
    EntityList* _list;
    Player *player1, *player2;
    CollisionManager colis;
    sf::Vector2u levelMapSize;
    Background back;
    EventManager* pEventManager;
    int levelRunning;
    char path[100];
    int reachEnd;

public:
    Level(const char* path = "", Player* p1 = NULL, Player* p2 = NULL, sf::Vector2u levelSize = sf::Vector2u(0, 0));
    virtual ~Level();
    void exec(float dt);

    Player* getP1() const { return player1; }
    Player* getP2() const { return player2; }
    void setP1(Player* p1) { player1 = p1; }
    void setP2(Player* p2) { player2 = p2; }
    CollisionManager* getCols() { return &colis; }
    void renderAll();
    void centerView();
    int isLevelRunning() const { return levelRunning; }
    void addEntity(Entity* ent) { _list->addEntity(ent); }
    void saveLvl();
    void setEnd(int end) { reachEnd = end; }
    int getNumLevel();
};
