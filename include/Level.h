#pragma once
#include "CollisionManager.h"
#include "Wizard.h"
#include "Entity.h"
#include "EntityList.h"
#include "Fireball.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "Platform.h"
#include "Player.h"
#include "PlayerControl.h"
#include "EventManager.h"
#include "stdafx.h"
#include "Wall.h"
#include "Archer.h"
#include "Arrow.h"
#include "Background.h"

class Level {
protected:
    GraphicManager* graphicM;
    EntityList _list;
    Player *player1, *player2;
    CollisionManager colis;
    InputManager im;
    PlayerControl pc;
    sf::Vector2u levelMapSize;
    Background back;
    EventManager* pEventManager;

public:
    Level(const char* path, sf::Vector2u levelSize = sf::Vector2u(0,0));
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
};
