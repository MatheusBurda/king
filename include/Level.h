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
#include "stdafx.h"

class Level {
protected:
    GraphicManager graphicM;
    EntityList _list;
    Player *player1, *player2;
    CollisionManager colis;
    InputManager im;
    PlayerControl pc;

public:
    Level();
    ~Level();
    void exec();
    virtual void createPlatform(sf::Vector2f pos) = 0;
    virtual void createPlayer(sf::Vector2f pos) = 0;
    virtual void createEnemy(sf::Vector2f pos) = 0;
};
