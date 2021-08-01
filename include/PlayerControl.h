#pragma once

#include "stdafx.h"
#include "Observer.h"

class Player;
class InputManager;

class PlayerControl : public Observer {
private:
    Player* pPlayer;

public:
    PlayerControl(InputManager* pIM);
    ~PlayerControl();

    void notify();
    void addPlayer(Player* p);
};