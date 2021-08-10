#include "PlayingGameState.h"
#include "Game.h"
#include "Level.h"

using namespace SM;

PlayingGameState::PlayingGameState(InputManager* IM, Game* pG) :
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    pLevel = NULL;
}

PlayingGameState::~PlayingGameState() {
}

void PlayingGameState::update(float dt) {
    if (!pLevel)
        pLevel = pGame->getpLevel();
    pLevel->exec(dt);

    if (!pLevel->isLevelRunning()) {
        endLevel(true);
    }
}

void PlayingGameState::render() {
    if (!pLevel)
        pLevel = pGame->getpLevel();
    pLevel->renderAll();
}

void PlayingGameState::endLevel(bool lvlEnded) {
    delete (pLevel);
    pLevel = NULL;
    pGame->setLevel(NULL);

    if (lvlEnded) {
        pGame->setCurrentLevel(2);
        changeState(stateID::newGame);
        //changeState(stateID::mainMenu);
    } else {
        changeState(stateID::mainMenu);
    }
}
