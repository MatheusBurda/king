#include "Game.h"

using namespace SM;

Game::Game() {
    pEventM = EventManager::getInstance();
    pGraphicM = GraphicManager::getInstance();

    pInputM = new InputManager;
    pEventM->setInputManager(pInputM);

    player1 = NULL;
    player2 = NULL;
    pLevel = NULL;
    lvlEnded = false;

    startStates();
    exec();
}

Game::~Game() {
    if (pLevel != NULL)
        delete (pLevel);
    if (player1)
        delete (player1);
    if (player2)
        delete (player2);
}

void Game::startStates() {
    State* pNewState = NULL;

    try {
        pNewState = new MainMenuState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new NewGameState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new PlayingGameState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new PauseMenuState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new LoadGameState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new LeaderboardState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

        pNewState = new EndGameState(pInputM, this);
        if (pNewState == NULL)
            throw 0;
        vectorOfStates.push_back(pNewState);

    } catch (int err) {
        if (err == 0) {
            cout << "Error allocating states " << endl;
            exit(1);
        }
    }

    changeCurrentState(stateID::mainMenu);
}

void Game::exec() {
    float dt;
    time.restart();

    while (pGraphicM->isWindowOpen()) {
        /* Check if any event occurred */
        pEventM->pollEvents();
        /* Get the elapsed time from last loop */
        dt = time.getElapsedTime().asSeconds();
        time.restart();
        if (dt > 0.01)
            dt = 0.01;
        /* Clear the screen to draw new stuff */
        pGraphicM->clear();
        /* Call update and render of current state */
        execCurrentState(dt);
        /* Display everything drawn */
        pGraphicM->display();
    }
}

void Game::save() {
    if (pLevel != NULL)
        pLevel->saveLvl();
}

Level* Game::getpLevel() const {
    return pLevel;
}

void Game::setLevel(Level* pLevel) {
    this->pLevel = pLevel;
}

Player* Game::getPLayer1() {
    if (player1 == NULL)
        player1 = new Player(true, pInputM);
    return player1;
}

Player* Game::getPLayer2() {
    if (player2 == NULL)
        player2 = new Player(false, pInputM);
    return player2;
}

bool Game::isTwoPlayersActive() const {
    return ((player1 != NULL) && (player2 != NULL));
}

int Game::getCurrentLevel() const {
    return currentLevel;
}

void Game::setCurrentLevel(int num) {
    currentLevel = num;
}

void Game::endGame() {
    pGraphicM->closeWindow();
}

void Game::deleteLevel() {
    if (pLevel != NULL)
        delete (pLevel);
    pLevel = NULL;
}

void Game::resetPlayers() {
    if (player1 != NULL)
        delete player1;
    if (player2 != NULL)
        delete player2;
    player1 = NULL;
    player2 = NULL;
}

bool Game::isPlaying() const {
    return lvlEnded;
}

void Game::setLvlEnded(bool x) {
    lvlEnded = x;
}