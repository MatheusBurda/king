#include "LoadGameState.h"

#include "Game.h"
#include "Level.h"

using namespace SM;

LoadGameState::LoadGameState(InputManager* IM, Game* pG) :
State(static_cast<StateMachine*>(pG)),
pGame(pG) { }

LoadGameState::~LoadGameState() {
}

void LoadGameState::update(float dt) {
    LevelMaker* maker = new LevelMaker();
    Level* lvl;

    ifstream Player2(("./assets/Saves/Player2.txt"), ios::in);
    if (!Player2) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }
    char info;

    if (Player2 >> info) {
        lvl = maker->loadMap(pGame->getPLayer1(), pGame->getPLayer2());
    } else
        lvl = maker->loadMap(pGame->getPLayer1(), NULL);
    Player2.close();

    if (!lvl) {
        cout << "ERROR LOADING LEVEL" << endl;
        changeState(stateID::mainMenu);
    } else {
        pGame->setLevel(lvl);
        changeState(stateID::playing);
        pGame->setCurrentLevel(lvl->getNumLevel());
        pGame->setLvlEnded(false);
    }
    delete (maker);
}

void LoadGameState::render() {
}

void LoadGameState::resetState() {
}