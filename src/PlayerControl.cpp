#include "PlayerControl.h"

#include "Player.h"

PlayerControl::PlayerControl(InputManager* pIM, Player* pP) :
Observer(pIM),
pPlayer(pP),
jump(sf::Keyboard::W),
left(sf::Keyboard::A),
right(sf::Keyboard::D),
attack(sf::Keyboard::Space) { }

PlayerControl::~PlayerControl() {
    pPlayer = NULL;
}

void PlayerControl::notify() {
    if (pPlayer == NULL) {
        cout << "ERROR pointer to player NULL on PlayerControl::notify()." << endl;
        exit(7);
    }
    if (sf::Keyboard::isKeyPressed(attack))
        pPlayer->setIsAttacking(true);

    if (sf::Keyboard::isKeyPressed(jump))
        pPlayer->jump();

    if (sf::Keyboard::isKeyPressed(left))
        pPlayer->walk(true);

    if (sf::Keyboard::isKeyPressed(right))
        pPlayer->walk(false);
}

void PlayerControl::addPlayer(Player* p) {
    pPlayer = p;
}

void PlayerControl::setKeys(sf::Keyboard::Key jump, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key attack) {
    this->jump = jump;
    this->left = left;
    this->right = right;
    this->attack = attack;
}