#pragma once

#include "stdafx.h"
#include "Observer.h"   

class Player;
class InputManager;

class PlayerControl : public Observer {
private:
    Player* pPlayer;
    sf::Keyboard::Key jump;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key attack;

public:
    PlayerControl(InputManager* pIM, Player* pP = NULL);
    ~PlayerControl();

    void notify();
    void addPlayer(Player* p);
    /* Colocar no UML somente setKeys(jump: Key, left: Key...) */
    void setKeys(sf::Keyboard::Key jump, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key attack);
};