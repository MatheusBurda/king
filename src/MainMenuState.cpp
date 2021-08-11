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
    bt->setMessage("NEW GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("LOAD GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 160));
    bt->setMessage("LEADERBOARD");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 240));
    bt->setMessage("QUIT GAME");
    vectorOfButtons.push_back(bt);

    max = 3;
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
        switch (selected) {
        case 0:
            changeState(stateID::newGame);
            break;
        case 1:
            changeState(stateID::loadGame);
            cout << "CARREGAR" << endl;
            break;
        case 2:
            //changeState(stateID::leaderboard);
            cout << "LEADERBOARD" << endl;
            break;
        case 3:
            pGame->endGame();
            break;
        default:
            break;
        }
        vectorOfButtons[selected]->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
    }
    active = false;
}
