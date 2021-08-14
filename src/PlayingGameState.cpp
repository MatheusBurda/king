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

    if (pLevel->isLevelRunning() == 0)
        endLevel(false);
    else if (pLevel->isLevelRunning() == -1)
        endLevel(true);
}

void PlayingGameState::render() {
    pLevel->renderAll();
}

void PlayingGameState::endLevel(bool lvlEnded) {
    pLevel = NULL;
    if (lvlEnded) {
        if (pGame->getCurrentLevel() == 2) {
            pGame->setLvlEnded(false);
            changeState(stateID::endGame);
        } else {
            pGame->setLvlEnded(true);
            pGame->setCurrentLevel(2);
            changeState(stateID::newGame);
        }
    } else {
        pGame->setLvlEnded(false);
        changeState(stateID::endGame);
    }
}

void PlayingGameState::resetState() {
    pLevel = pGame->getpLevel();
}