#pragma once
#include "CollisionManager.h"
#include "Enemy.h"
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

class Level {
protected:
    GraphicManager graphicM;
    EntityList _list;
    Player *player1, *player2;
    CollisionManager colis;
    InputManager im;
    PlayerControl pc;
    EventManager evntM;

public:
    Level();
    ~Level();
    void exec();

    GraphicManager* getGM() { return &graphicM; }
    EntityList* getList() { return &_list; }
    Player* getP1() { return player1; }
    Player* getP2() { return player2; }
    void setP1(Player* p1) { player1 = p1; }
    void setP2(Player* p2) { player2 = p2; }
    CollisionManager getCols() { return colis; }
   
};
