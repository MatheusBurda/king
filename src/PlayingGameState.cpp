#include "PlayingGameState.h"
#include "Game.h"

using namespace SM;

PlayingGameState::PlayingGameState(InputManager* IM, Game* pG) :
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    pLevel = NULL;
}

PlayingGameState::~PlayingGameState() {
}

void PlayingGameState::update() {
    if (!pLevel)
        pLevel = pGame->getCurrentLevel();
    pLevel->exec();

    if (!pLevel->isLevelRunning()) {
        endLevel(false);
    }
}

void PlayingGameState::render() {
    if (!pLevel)
        pLevel = pGame->getCurrentLevel();
    pLevel->renderAll();
}

void PlayingGameState::endLevel(bool lvlEnded) {
    delete (pLevel);
    pLevel = NULL;
    pGame->setLevel(NULL);

    if (lvlEnded) {
        pGame->setCurrentLevel(2);
        changeState(stateID::newGame);
    } else {
        changeState(stateID::mainMenu);
    }
}
