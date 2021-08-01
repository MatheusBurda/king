#include "PlayerControl.h"

#include "Player.h"

PlayerControl::PlayerControl(InputManager* pIM) :
Observer(pIM) {
}

PlayerControl::~PlayerControl() {
    pPlayer = NULL;
}

void PlayerControl::notify() {
    pPlayer->setIsAttacking(true);
}

void PlayerControl::addPlayer(Player* p) {
    pPlayer = p;
}