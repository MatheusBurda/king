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
    pLevel->exec(dt);

    if (!pLevel->isLevelRunning()) {
        endLevel(true);
    }
}

void PlayingGameState::render() {
    pLevel->renderAll();
}

void PlayingGameState::endLevel(bool lvlEnded) {
    pLevel = NULL;
    if (lvlEnded) {
        pGame->setCurrentLevel(2);
        changeState(stateID::endGame);
    } else {
        changeState(stateID::mainMenu);
    }
}

void PlayingGameState::resetState() {
    pLevel = pGame->getpLevel();
}