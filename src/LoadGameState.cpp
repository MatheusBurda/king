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
    Level* lvl = pGame->getpLevel();
    if (lvl != NULL) {
        delete (lvl);
    }
    LevelMaker* maker = new LevelMaker();
    lvl = maker->loadMap(pGame->getPLayer1(), pGame->getPLayer2());
    if (!lvl) {
        cout << "FAZER AS COISAS DE LOAD SE DEU ERRADO" << endl;
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
