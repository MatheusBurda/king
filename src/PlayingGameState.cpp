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
    pLevel = NULL;
}

void PlayingGameState::render() {
    if (!pLevel)
        pLevel = pGame->getpLevel();
    pLevel->renderAll();
    pLevel = NULL;
}

void PlayingGameState::endLevel(bool lvlEnded) {
    pGame->deleteLevel();
    pLevel = NULL;
    if (lvlEnded) {
        pGame->setCurrentLevel(2);
        changeState(stateID::newGame);
        //changeState(stateID::mainMenu);
    } else {
        changeState(stateID::mainMenu);
        pGame->setCurrentLevel(1);
    }
}
