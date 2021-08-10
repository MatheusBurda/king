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
    Level* lvl = maker->loadMap();
    if (!lvl) {
        cout << "FAZER AS COISAS DE LOAD SE DEU ERRADO" << endl;
    }
}

void LoadGameState::render() {
    
}
