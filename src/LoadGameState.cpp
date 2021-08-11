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
    Player2 >> info;
    Player2.close();

    if (info != 0) {
        lvl = maker->loadMap(pGame->getPLayer1(), pGame->getPLayer2());
    } else
        lvl = maker->loadMap(pGame->getPLayer1(), NULL);

    if (!lvl) {
        cout << "FAZER AS COISAS DE LOAD DERAM ERRADO" << endl;
        changeState(stateID::mainMenu);
    } else {
        pGame->setLevel(lvl);
        changeState(stateID::playing);
        pGame->setCurrentLevel(lvl->getNumLevel());
    }
    delete (maker);
}

void LoadGameState::render() {
}

void LoadGameState::resetState() {
}