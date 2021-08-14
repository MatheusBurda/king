#include "MainMenuState.h"
#include "Game.h"

using namespace SM;

MainMenuState::MainMenuState(InputManager* IM, Game* pG) :
Menu(IM, BACKGROUND_MAIN_MENU),
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    GraphicManager* GM = GraphicManager::getInstance();
    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
    bt->setMessage("LEVEL 1");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("LEVEL 2");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 160));
    bt->setMessage("LOAD GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 240));
    bt->setMessage("LEADERBOARD");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 320));
    bt->setMessage("QUIT GAME");
    vectorOfButtons.push_back(bt);

    max = 4;
}

MainMenuState::~MainMenuState() {
}

void MainMenuState::update(float dt) {
    active = true;
}

/* Menu operation to render all it's objects. */
void MainMenuState::render() {
    updateView();
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

void MainMenuState::exec() {
    if (active) {
        active = false;
        switch (selected) {
        case 0:
            pGame->setCurrentLevel(1);
            changeState(stateID::newGame);
            break;
        case 1:
            pGame->setCurrentLevel(2);
            changeState(stateID::newGame);
            break;
        case 2:
            changeState(stateID::loadGame);
            break;
        case 3:
            changeState(stateID::leaderboard);
            break;
        case 4:
            pGame->endGame();
            break;
        default:
            break;
        }
    }
}

void MainMenuState::resetState() {
    vectorOfButtons[selected]->select(false);
    selected = 0;
    vectorOfButtons[selected]->select(true);

    pGame->deleteLevel();
    pGame->resetPlayers();
    pGame->setCurrentLevel(1);
}