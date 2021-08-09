#include "NewGameState.h"
#include "Game.h"

using namespace SM;

NewGameState::NewGameState(InputManager* IM, Game* pG) :
Menu(IM, BACKGROUND_MAIN_MENU),
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    GraphicManager* GM = GraphicManager::getInstance();
    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
    bt->setMessage("ONE PLAYER");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("TWO PLAYERS");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 160));
    bt->setMessage("RETURN");
    vectorOfButtons.push_back(bt);

    selected = 0;

    max = 2;

    onePlayer = true;
}

NewGameState::~NewGameState() {
}

void NewGameState::update() {
    if (pGame->getCurrentLevel() == 1)
        active = true;
    else
        startNewLevel(true);
}

/* Menu operation to render all it's objects. */
void NewGameState::render() {
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

void NewGameState::exec() {
    if (active) {
        switch (selected) {
        case 0:
            startNewLevel(true);
            break;
        case 1:
            startNewLevel(false);
            break;
        case 2:
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
    }
    active = false;
}

void NewGameState::startNewLevel(bool isOnePLayer) {
    onePlayer = isOnePLayer;

    Level* pLevel = pGame->getpLevel();
    if (pLevel != NULL) {
        delete (pLevel);
    }

    int currentLevel = pGame->getCurrentLevel();

    Player* player1 = pGame->getPLayer1();
    player1->reset();

    Player* player2 = NULL;

    if (!onePlayer) {
        player2 = pGame->getPLayer2();
        player2->reset();
    }

    if (currentLevel == 1) {
        FieldBuilder* fb = new FieldBuilder("./assets/Backgrounds/montanha.png", player1, player2, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(fb);
    }

    else if (currentLevel == 2) {
        LoadBuilder* cb = new LoadBuilder("./assets/Backgrounds/bck1.png", player1, player2, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(cb);
    }

    /* else if (currentLevel == 2) {
        CastleBuilder* cb = new CastleBuilder("./assets/Backgrounds/bck1.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(cb);
    } */

    else {
        cerr << "GAME - Couldnt create a new LEVEL" << endl;
        std::exit(35);
    }
    pGame->setLevel(pLevel);
    pGame->changeCurrentState(stateID::playing);
}
