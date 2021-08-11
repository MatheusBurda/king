#include "PauseMenuState.h"
#include "Game.h"

using namespace SM;

PauseMenuState::PauseMenuState(InputManager* IM, Game* pG) :
Menu(IM, BACKGROUND_PATH),
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    GraphicManager* GM = GraphicManager::getInstance();

    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 - 80));
    bt->setMessage("RESUME GAME");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
    bt->setMessage("SAVE GAME");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("Exit TO Main MENU");
    vectorOfButtons.push_back(bt);

    selected = 0;
}

PauseMenuState::~PauseMenuState() {
}

void PauseMenuState::update(float dt) {
    active = true;
}

/* Menu operation to render all it's objects. */
void PauseMenuState::render() {
    updateView();
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

void PauseMenuState::exec() {
    if (active) {
        switch (selected) {
        case 0:
            changeState(stateID::playing);
            break;
        case 1:
            //changeState(stateID::loadGame);
            cout << "SALVAR" << endl;
            break;
        case 2:
            pGame->deleteLevel();
            pGame->setCurrentLevel(0);
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
        vectorOfButtons[selected]->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
    }
    /* Trigger to open the pause menu */
    else if (pGame->getCurrentState() == stateID::playing) {
        changeState(stateID::pauseMenu);
    }
    active = false;
}
