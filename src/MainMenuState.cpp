#include "MainMenuState.h"

using namespace SM;

MainMenuState::MainMenuState(InputManager* IM, StateMachine* pSM) :
Menu(IM, BACKGROUND_MAIN_MENU),
State(pSM) {
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

void MainMenuState::update() {
    active = true;
}

/* Menu operation to render all it's objects. */
void MainMenuState::render() {
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

void MainMenuState::exec() {
    /* switch (selected) {
    case 0:
        changeState(stateID::newGame);
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    } */
    if (active) {
        switch (selected) {
        case 0:
            changeState(stateID::newGame);
            break;
        case 1:
            //changeState(stateID::loadGame);
            cout << "CARREGAR" << endl;
            break;
        case 2:
            //changeState(stateID::leaderboard);
            cout << "LEADERBOARD" << endl;
            break;
        case 3:
            changeState(stateID::exit);
            break;
        default:
            break;
        }
    }
    active = false;
}
