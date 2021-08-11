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

void NewGameState::update(float dt) {
    if (pGame->getCurrentLevel() == 1)
        active = true;
    else
        startNewLevel(onePlayer);
}

/* Menu operation to render all it's objects. */
void NewGameState::render() {
    updateView();
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
        vectorOfButtons[selected]->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
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

    if (currentLevel <= 1) {
        LevelMaker* maker = new LevelMaker();
        pLevel = maker->buildMap("./assets/Backgrounds/montanha.png", player1, player2, 1);
        delete (maker);
    }
    else if (currentLevel == 2) {
        LevelMaker* maker = new LevelMaker();
        pLevel = maker->buildMap("./assets/Backgrounds/montanha.png", player1, player2, 2);
        delete (maker);
    }

    else {
        cerr << "GAME - Couldnt create a new LEVEL - no existing level" << endl;
        std::exit(35);
    }
    pGame->setLevel(pLevel);
    pGame->changeCurrentState(stateID::playing);
}
