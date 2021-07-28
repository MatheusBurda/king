#pragma once
#include "stdafx.h"
#include "CollisionManager.h"
#include "Enemy.h"
#include "Entity.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"
#include "Player.h"
#include "Fireball.h"

class Level
{
protected:
    GraphicManager graphicM;
    EntityList _list;
    Player* player1, *player2;
    CollisionManager colis;

public:
    Level();
    ~Level();
    void exec();
    virtual void createPlatform() = 0;
    virtual void createPlayer() = 0;
    virtual void createEnemy() = 0;

};

